#include "stock.hpp"
#include "libraries/json.hpp"

using namespace nlohmann;

// Конструктор
Stock::Stock(int count)
{
    cnt = count;
    mas = new Course[count];
    for (int i=0; i<cnt; i++)
        mas[i] = {};
}

Stock::Stock()
{
    cnt = 0;
    mas = new Course[0];
}

// Деструктор
Stock::~Stock()
{
    delete[] mas;
    cnt = 0;
}

void Stock::add(Course _course)
{
    cnt++;
    Course* new_mas = new Course[cnt];
    for (int i=0; i<cnt-1; i++)
        new_mas[i] = mas[i];
    Course* old_mas = mas;
    mas = new_mas;
    delete[] old_mas;

    mas[cnt-1] = _course;
}

void Stock::pop(int index)
{
    int old_cnt = cnt;
    cnt--;
    Course* new_mas = new Course[cnt];
    
    for (int i=0, j=0; i<old_cnt; i++)
        if (i != index)
        {
            new_mas[j] = mas[i];
            j++;
        }

    Course* old_mas = mas;
    mas = new_mas;
    delete[] old_mas;
}

void Stock::get_from_file(string path)
{
    ifstream inp;
    inp.open(path);

    if (inp)
    {
        int old_cnt = cnt;
        inp >> cnt;

        Course* new_mas = new Course[cnt];
        for (int i=0; i<old_cnt; i++)
            new_mas[i] = mas[i];
        delete[] mas;
        mas = new_mas;

        for (int i=0; i<cnt; i++)
            mas[i].read_from_file(inp);
    }
    else
       cerr << "Заданного файла не существует" << endl;
}

void Stock::save_to_file(string path)
{
    ofstream out;
    out.open(path);

    out << cnt << endl;

    for (int i=0; i<cnt; i++)
        mas[i].write_to_file(out);
}

void Stock::print_all()
{
    for (int i=0; i<cnt; i++)
        mas[i].print();
}

void Stock::print(int i)
{
    if (i >= 0 && i < cnt)
        mas[i].print();
    else
        cerr << "Элемента с нужным индексом не существует" << endl;
}

double Stock::diff(Course left, Course right)
{
    return (left.get_rate() - right.get_rate());
}

void Stock::print_exp()
{
    Course usd = {};
    bool usd_exists = 0;

    std::cout << "Стоят дороже доллара:" << endl;

    for (int i=0; i<cnt && usd_exists==0; i++)
        if (mas[i].get_code().compare("USD") == 0)
        {
            usd = mas[i];
            usd_exists = 1;
        }

    if (usd_exists==1)
    {
        for (int i=0; i<cnt; i++)
            if (diff(usd, mas[i]) < 0)
            {
                mas[i].print();
                cout << endl;
            }
    }
    else
        std::cerr << "\nДоллара в выборке нет, сравнение невозможно" << endl;
}

int Stock::get_cnt()
{
    return cnt;
}

void Stock::read_from_json(string path)
{
    json file;

    ifstream in(path);
    if (in.is_open())
    {

        in >> file;
        cout << "Файл прочитан" << endl;
        in.close();

        int old_cnt = cnt;
        cnt = file["count"];

        Course* new_mas = new Course[cnt];
        delete[] mas;
        mas = new_mas;

        for (int i=0; i<cnt; i++)
        {
            json value = file["values"][i];
            Course tmp = Course();

            tmp.set_currency(value["currency"]);
            tmp.set_state(value["state"]);
            tmp.set_code(value["code"]);
            tmp.set_subunit(value["subunit"]);
            tmp.set_fraction(value["fraction"]);
            tmp.set_rate(value["rate"]);
            mas[i] = tmp;
        }
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
    }
}

void Stock::write_to_json(string path)
{
    json file;

    file["count"] = cnt;

    for (int i=0; i<cnt; i++)
    {
        json value;
        value["currency"] = mas[i].get_currency();
        value["state"] = mas[i].get_state();
        value["code"] = mas[i].get_code();
        value["subunit"] = mas[i].get_subunit();
        value["fraction"] = mas[i].get_fraction();
        value["rate"] = mas[i].get_rate();
        file["values"].push_back(value);
    }

    ofstream out(path);
    if (out.is_open())
    {
        out << file.dump(4);
        cout << "Файл записан" << endl;
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
    }
}
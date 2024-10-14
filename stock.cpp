#include "stock.h"

// Конструктор
Stock::Stock(int count)
{
    cnt = count;
    mas = new Course[count];
    for (int i=0; i<cnt; i++)
        mas[i] = {};
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
    cnt--;
    Course* new_mas = new Course[cnt];
    
    for (int i=0, j=0; i<cnt; i++)
        if (j != index)
        {
            new_mas[j] = mas[i];
            j++;
            continue; // это бесполезная хрень
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
        cout << "Заданного файла не существует" << endl;
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
        std::cout << "\tДоллара в выборке нет, сравнение невозможно" << endl;
}

int Stock::get_cnt()
{
    return cnt;
}
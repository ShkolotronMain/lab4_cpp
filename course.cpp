#include <iostream>
#include "course.hpp"
#include "libraries/json.hpp"

Course::Course()
{

}

Course::~Course()
{

}

void Course::print()
{
    cout << "===================" << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << currency << endl;
    cout << state << endl;
    cout << code << endl;
    cout << "1 " + code + " = " << rate << endl;
    cout << "===================" << endl;
}

void Course::read_from_file(ifstream& fp)
{
    string trash;
    getline(fp, trash);

    getline(fp, currency);
    getline(fp, state);
    getline(fp, code);
    getline(fp, subunit);
    fp >> fraction;
    fp >> rate;
}

void Course::read_from_console()
{
    string trash;

    getline(cin, trash);
    cout << "Введите название валюты:" << endl;
    getline(cin, currency);
    cout << "Введите государство:" << endl;
    getline(cin, state);
    cout << "Введите код валюты:" << endl;
    getline(cin, code);
    cout << "Введите название разменной валюты:" << endl;
    getline(cin, subunit);
    cout << "Сколько разменной валюты в основной:" << endl;
    cin >> fraction;
    cout << "Введите курс валюты к российскому рублю:" << endl;
    cin >> rate;
    getline(cin, trash);   
}

void Course::write_to_file(ofstream& fp)
{
    fp << currency << endl;
    fp << state << endl;
    fp << code << endl;
    fp << subunit << endl;
    fp << fraction << endl;
    fp << rate << endl;
}

string Course::get_currency()
{
    return currency;
}

string Course::get_state()
{
    return state;
}

string Course::get_subunit()
{
    return subunit;
}

string Course::get_code()
{
    return code;
}

int Course::get_fraction()
{
    return fraction;
}

double Course::get_rate()
{
    return rate;
}

void Course::set_currency(string cur)
{
    currency = cur;
}

void Course::set_state(string stat)
{
    state = stat;
}

void Course::set_code(string cod)
{
    code = cod;
}

void Course::set_subunit(string sub)
{
    subunit = sub;
}

void Course::set_fraction(int frac)
{
    fraction = frac;
}

void Course::set_rate(double rat)
{
    rate = rat;
}

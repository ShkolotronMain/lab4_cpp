#include <iostream>
#include "course.h"

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

string Course::get_code()
{
    return code;
}

double Course::get_rate()
{
    return rate;
}

#include <iostream>
#include "stock.h"
#include "course.h"

using namespace std;

int main()
{
    Stock obj(0);

    bool running = 1;
    while (running)
    {
        cout << "[LAB]> ";
        string command;
        cin >> command;
        cout << endl;

        if (command == "add")
        {
            Course nc = Course();
            nc.read_from_console();
            obj.add(nc);
        }
        else if (command == "pop")
        {
            int count = obj.get_cnt();
            int c;
            cout << "Введите индекс удаляемого элемента: ";
            cin >> c;
            if (c>=0 && c<count)
                obj.pop(c);
            else
                cout << "Элемент с данным индексом отсутствует" << endl;
        }
        else if (command == "get_from_file")
        {
            string path;
            cout << "Введите путь к файлу" << endl;
            cin >> path;

            obj.get_from_file(path);
        }
        else if (command == "save_to_file")
        {
            string path;
            cout << "Введите путь к файлу" << endl;
            cin >> path;

            obj.save_to_file(path);
        }
        else if (command == "print_all")
        {
            obj.print_all();
        }
        else if (command == "print_exp")
        {
            obj.print_exp();
        }
        else if (command == "get_cnt")
        {
            cout << obj.get_cnt() << endl;
        }
        else if (command == "help")
        {
            cout << "Список доступных комманд:\n add - добавить в контейнер\n pop - убрать из контейнера\n get_from_file - ввести несколько из файла (перезапись)\n save_to_file - сохранить всё в файл\n print_all - вывести все\n print_exp - вывести те, которые дороже доллара\n get_cnt - получить количество\n help - список команд\n exit - выход\n" << endl; 
        }
        else if (command == "exit")
        {
            cout << "Выход" << endl;
            running = 0;
        }
        else
        {
            cout << "Неверная комманда" << endl;
            cout << "Для получения списка комманд введите help" << endl;
        }
    }

    return 0;
}
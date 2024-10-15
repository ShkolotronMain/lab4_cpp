#include <iostream>
#include <fstream>
#include "course.hpp"

#ifndef STOCK_H
#define STOCK_H

class Stock
{
    private:
        Course* mas;
        int cnt;

        double diff(Course, Course);

    public:
        Stock(int);
        Stock();
        ~Stock();

        void add(Course _course);
        void pop(int index);

        void get_from_file(string path);
        void save_to_file(string path);

        void read_from_json(string path);
        void write_to_json(string path);

        void print_all();
        void print_exp();

        int get_cnt();
};

#endif
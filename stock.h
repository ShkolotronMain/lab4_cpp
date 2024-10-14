#include <iostream>
#include <fstream>
#include "course.h"

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
        ~Stock();

        void add(Course _course);
        void pop(int index);

        void get_from_file(string path);
        void save_to_file(string path);

        void print_all();
        void print_exp();

        int get_cnt();
};

#endif
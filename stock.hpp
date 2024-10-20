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

        void add(Course);
        void pop(int);

        void get_from_file(string);
        void save_to_file(string);

        void read_from_json(string);
        void write_to_json(string);

        void print_all();
        void print_exp();
        void print(int);

        int get_cnt();
};

#endif
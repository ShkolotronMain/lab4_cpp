#include <string>
#include <fstream>

using namespace std;

#ifndef COURSE_H
#define COURSE_H

class Course
{
    private:
        string currency;
        string state;
        string code;
        string subunit;
        int fraction;
        double rate;

    public:
        Course();
        ~Course();

        void read_from_file(ifstream&);
        void read_from_console();

        void print();
        void write_to_file(ofstream&);

        string get_currency();
        string get_state();
        string get_code();
        string get_subunit();
        int get_fraction();
        double get_rate();

        void set_currency(string);
        void set_state(string);
        void set_code(string);
        void set_subunit(string);
        void set_fraction(int);
        void set_rate(double);
};

#endif
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
        Course(string, string, string, string, int, double);
        ~Course();

        void read_from_file(ifstream& fp);
        void read_from_console();

        void print();
        void write_to_file(ofstream& fp);

        string get_currency();
        string get_state();
        string get_code();
        string get_subunit();
        int get_fraction();
        double get_rate();
};

#endif
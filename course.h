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

        void read_from_file(ifstream& fp);
        void read_from_console();

        void print();
        void write_to_file(ofstream& fp);

        string get_code();
        double get_rate();
};

#endif
#include <iostream>
#include <string>
#ifndef DATE_H
#define DATE_H
using namespace std;

char slash;
class Date{
    public:
        unsigned int _day;
        unsigned int _month;
        unsigned int _year;
        friend ostream &operator << (ostream &output,Date &d){
            string date=to_string(d._day)+slash+to_string(d._month)+slash+to_string(d._year);
            output<<date;
            return output;
        }
        friend istream &operator >> (istream &input,Date &d){
            input>>d._day>>slash>>d._month>>slash>>d._year;
            return input;
        }
};
#endif

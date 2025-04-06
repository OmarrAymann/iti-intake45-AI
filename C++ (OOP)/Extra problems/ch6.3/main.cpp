#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    int hours;
    int minutes;
    int seconds;

public:
    int gethours()
    {
        return hours ;
    }
    int getminutes()
    {
        return minutes ;
    }
        int getseconds()
    {
        return seconds ;
    }
    void sethour(int _hours)
    {
        hours=_hours;
    }
    void setminutes(int _minutes)
    {
        minutes=_minutes;
    }
    void setseconds(int _seconds)
    {
        seconds=_seconds;
    }
    Time()
    {
         hours=0;
         minutes=0;
         seconds=0;
    }
    Time(int _hours, int _minutes, int _second)
    {
         hours=_hours;
         minutes=_minutes;
         seconds=_second;
    }
 void print()
    {
        if (seconds >= 60)
            {
                minutes += seconds / 60;
                seconds %= 60;
            }
        if (minutes >= 60)
            {
                hours += minutes / 60;
                minutes %= 60;
            }
    cout<<"Hour:"<<hours<<" ,Minute :"<<minutes<<" ,Second :"<<seconds;
    }
    Time operator+ (Time t)
    {
        Time result;
        result.hours = hours + t.hours;
        result.minutes = minutes + t.minutes;
        result.seconds = seconds + t.seconds;
        return result;
    }
};

int main()
{
    Time t1(1, 11, 111);
    Time t2(2, 22, 222);
    Time t3;
    cout << "1) time: ";
    t1.print();
    cout<<endl;
    cout << "2) time: ";
    t2.print();
    cout<<endl;
    t3=t1+t2;
    cout << "summation : ";
    t3.print();

    return 0;
}

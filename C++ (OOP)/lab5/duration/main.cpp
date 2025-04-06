#include <iostream>

using namespace std;

class duration
{
    int hour;
    int min;
    int sec;
public :
    int gethour()
    {
        return hour ;
    }
    int getmin()
    {
        return min ;
    }
        int getsec()
    {
        return sec ;
    }
    void sethour(int _hour)
    {
        hour=_hour;
    }
    void setmin(int _min)
    {
        min=_min;
    }
    void setsec(int _sec)
    {
        sec=_sec;
    }
    duration (int _hour, int _min, int _sec)
    {
        hour=_hour;
        min=_min;
        sec=_sec;
    }
    duration (int _sec)
    {
        hour=0;
        min=0;
        sec=_sec;
    }
    duration ()
    {
        hour=0;
        min=0;
        sec=0;
    }

    void print()
    {
        if (sec >= 60)
            {
                min += sec / 60;
                sec %= 60;
            }
        if (min >= 60)
            {
                hour += min / 60;
                min %= 60;
            }
    cout<<"Hour:"<<hour<<" ,Minute :"<<min<<" ,Second :"<<sec;
    }
    duration operator+ (duration d)
    {
        duration result;
        result.hour = hour + d.hour;
        result.min = min + d.min;
        result.sec = sec + d.sec;
        return result;
    }
    duration operator+ (int x)
    {
        duration result;
        result.sec = sec + x;
        result.min = min ;
        result.hour = hour ;
        return result;
    }
    duration operator++ (int)
    {
        duration temp = (*this);
        min=min+1;
        return temp;
    }
    duration operator-- (int)
    {
        duration temp = (*this);
        min=min-1;
        return temp;
    }
    friend duration operator+ (int x,duration d);
};


duration operator+ (int x,duration d)
{
    duration result;
    result.sec=d.sec + x;
    result.min=d.min;
    result.hour=d.hour;
}
int main()
{
    duration d1(0,59,61);
    /*cout<<("please enter the hour : ");
    cin>>hour;
    cout<<("please enter the minute : ");
    cin>>min;
    cout<<("please enter the second : ");
    cin>>sec;
    d1.sethour(hour);
    d1.setmin(min);
    d1.setsec(sec);*/
    duration d2(3600);
    duration d3;
    duration d4;
    duration d5;
    duration d6;
    cout<<endl<<endl<<"D1 :";
    d1.print();
    d1++;
    cout<<endl<<endl<<"D1 ++:";
    d1.print();
    d1--;
    cout<<endl<<endl<<"D1 --:";
    d1.print();
    cout<<endl<<endl<<"D2 :";
    d2.print();
    d3=d1+d2;
    cout<<endl<<endl<<"D3=D1+D2 : ";
    d3.print();
    d4=d1+360;
    cout<<endl<<endl<<"D4=D1+360SEC :";
    d4.print();
    d5=360+d1;
    cout<<endl<<endl<<"D5=360SEC+D1 :";
    d5.print();

    return 0;
}

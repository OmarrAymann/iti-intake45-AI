#include <iostream>

using namespace std;
class complex
{
    int realnum ;
    int complexnum ;
    public :
    int getrealnum()
    {
        return realnum ;
    }
    int getcomplexnum()
    {
        return complexnum ;
    }
    void setrealnum(int _realnum)
    {
        realnum=_realnum;
    }
    void setcomplexnum(int _complexnum)
    {
        complexnum=_complexnum;
    }
};

int main()
{
    int realnum , complexnum ;
    complex e1 ;
    cout<<("please enter the real number : ");
    cin>>realnum;
    cout<<("please enter the complex number :");
    cin>>complexnum;
    e1.setrealnum(realnum);
    e1.setcomplexnum(complexnum);
    if (complexnum>=1)
        cout<<"the number = "<<e1.getrealnum()<<"+"<<e1.getcomplexnum()<<"i";
    else if (complexnum<0)
        cout<<"the number = "<<e1.getrealnum()<<e1.getcomplexnum()<<"i";
    else
        cout<<"the number = "<<e1.getrealnum();
    return 0;
}

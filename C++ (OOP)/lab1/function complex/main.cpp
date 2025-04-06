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
void setcomplex(complex complexnumber)
{
    cout<<"the complex number = "<<complexnumber.getrealnum()<<"+"<<complexnumber.getcomplexnum()<<"i";
}
int main()
{
    int realnum , complexnum ;
    complex complexnumber ;
    cout<<("please enter the real number : ");
    cin>>realnum;
    cout<<("please enter the imagine number :");
    cin>>complexnum;
    complexnumber.setrealnum(realnum);
    complexnumber.setcomplexnum(complexnum);
    setcomplex(complexnumber);
    return 0;
}

#include <iostream>
# include <string.h>
using namespace std;
class complexnum
{

    int real , img ;

    public :
    int getreal()
    {
        return real ;
    }
    int getimg()
    {
        return img ;
    }
    void setreal(int _real)
    {
        real=_real;
    }
    void setimg(int _img)
    {
        img=_img;
    }
    complexnum (int _real, int _img)
    {
        real=_real;
        img=_img;
    }
    complexnum (int _real)
    {
        real=_real;
        img=0;
    }
    complexnum ()
    {
        real=0;
        img=0;
    }
void print()
{
    if(img >=1)
    cout<<"the complex number :"<<real<<"+"<<img<<"j";
    else if (img == 0)
        cout<<"the complex number :"<<real;
    else
        cout<<"the complex number :"<<real<<img<<"j";
}
complexnum add(complexnum c)
{
    complexnum result;
    result.setreal(real + c.real);
    result.setimg(img + c.img);
    return result ;
}
};


int main()
{
    int real , img;
    complexnum e1;
    complexnum e2(0);
    complexnum e3(5,10);
    complexnum e4;
    complexnum e5;
    cout<<("please enter first the real number : ");
    cin>>real;
    cout<<("please enter first the  imagine number:");
    cin>>img;
    e4.setreal(real);
    e4.setimg(img);
    cout<<("\n");
    cout<<("please enter second the real number : ");
    cin>>real;
    cout<<("please enter second the  imagine number:");
    cin>>img;
    e5.setreal(real);
    e5.setimg(img);
    cout<<("\n");
    e1.print();
    cout<<endl;
    e2.print();
    cout<<endl;
    e3.print();
    cout<<endl;
    e4.print();
    cout<<endl;
    e5.print();
    cout<<("\n");
    complexnum e=e4.add(e5);
    cout<<("\n the summation of ");
    e.print();
    return 0;
}


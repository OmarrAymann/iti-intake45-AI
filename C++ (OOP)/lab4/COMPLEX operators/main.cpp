#include <iostream>
# include <string.h>
using namespace std;
class complexnum
{
    int real;
    int img;

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
    complexnum operator+ (complexnum c) //complex sum
    {
        complexnum result;
        result.real = real + c.real;
        result.img = img + c.img;
        return result;
    }
    complexnum operator+ (int x) //real part only
    {
        complexnum result;
        result.real = real + x;
        result.img = img ;
        return result;
    }
    int operator== (complexnum c) //equality
    {
        return real==c.real && img==c.img;
    }
    int operator!= (complexnum c) //not equal
    {
        return !(*this==c);
    }
    complexnum operator++ () //prefix
    {
        real=real+1;
        return(*this);
    }
    complexnum operator++ (int) //post
    {
        complexnum temp = (*this);
        real=real+1;
        return temp;
    }
    explicit operator int ()
    {
        return real;
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
friend complexnum operator+ (int x,complexnum c);

};
complexnum operator+ (int x,complexnum c)
{
    complexnum result;
    result.real=c.real + x;
    result.img=c.img;
}

int main()
{
    int real;
    int img;
    int x;
    complexnum c1,c2,c3;
    cout<<("please enter first the real number : ");
    cin>>real;
    cout<<("please enter first the  imagine number:");
    cin>>img;
    c1.setreal(real);
    c1.setimg(img);
    cout<<("\nplease enter second the real number : ");
    cin>>real;
    cout<<("please enter second the  imagine number:");
    cin>>img;
    c2.setreal(real);
    c2.setimg(img);
    cout<<("\n");
    c3=c1+c2;
    cout<<"the summation of ";
    c3.print();
    cout<<endl;
    x =(int)c1;
    cout<<endl<<"the real part ="<<x<<endl;
    if (c1 != c2)
        cout<<endl<<"not equal"<<endl;
    else
        cout<<endl<<"equal"<<endl;
    c1++.print();
    cout<<endl;
    c1.print();


    return 0;
}


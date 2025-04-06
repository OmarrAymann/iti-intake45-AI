#include <iostream>

using namespace std;

class complexnum
{
    int real;
    int img;
    static int counter;

    public :
    int getreal(){return real ;}
    int getimg(){return img ;}
    static int getcounter()
    {
        return counter;
    }

    void setreal(int _real){real=_real;}
    void setimg(int _img){img=_img;}

    complexnum (int _real, int _img)
    {real=_real;img=_img;counter++;}
    complexnum (int _real)
    {real=_real;img=0;counter++;}
    complexnum ()
    {real=0;img=0;counter++;}

    void print()
    {
    if(img >=1)
    cout<<"the complex number :"<<real<<"+"<<img<<"j";
    else if (img == 0)
        cout<<"the complex number :"<<real;
    else
        cout<<"the complex number :"<<real<<img<<"j";
    }
    friend ostream& operator<< (ostream& os ,complexnum c)
    {
        counter++;
        if (c.img>0)
            os<<c.real<<"+"<<c.img<<"j";
        else if (c.img<0)
            os<<c.real<<c.img<<"j";
        else
            os<<c.real;

        return os;
    }

    ~complexnum()
    {
        counter-- ;
        cout<<"\ndestructor";
    }
};

int complexnum::counter=0;

int main()
{
    int real;
    int img;
    cout<<"\ncounter = "<<complexnum::getcounter()<<endl;
    complexnum c1;
    complexnum c2(10,20);
    complexnum c3(10);
    complexnum c4;
    cout<<("please enter first the real number : ");
    cin>>real;
    cout<<("please enter first the  imagine number:");
    cin>>img;
    c1.setreal(real);
    c1.setimg(img);
    cout<<"the complex number = "<<c1;
    cout<<"\ncounter = "<<complexnum::getcounter()<<endl;
    return 0;
}


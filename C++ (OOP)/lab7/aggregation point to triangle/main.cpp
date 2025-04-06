#include <iostream>

using namespace std;

class point
{
    int x;
    int y;
public:
    int getx()
    {
        return x ;
    }
    int gety()
    {
        return y ;
    }
    void setx(int _x)
    {
        x=_x;
    }
    void sety(int _y)
    {
        y=_y;
    }
    point (int _x, int _y)
    {
        x=_x;
        y=_y;
    }
    point (int _x)
    {
        x=_x;
        y=0;
    }
    point ()
    {
        x=y=0;
    }
    void print()
    {
        cout<<"("<<x<<","<<y<<")";
    }
    ~ point()
    {
        cout<<"\npoint destructor";
    }
};
class rect
{
    point *ul;
    point *lr;
public:
    point* getxul()
    {
        return ul;
    }
    point* getlr()
    {
        return lr;
    }
    void setul(point* _ul)
    {
        ul=_ul;
    }
    void setlr(point* _lr)
    {
        lr=_lr;
    }
    rect(point* _ul,point* _lr)
    {
         ul=_ul;
         lr=_lr;
    }
    void print()
    {
        cout<<"rect = ";
        lr->print();
        ul->print();
    }
    ~rect()
    {
        cout<<"\n\nrect destructor";
    }
};
int main()
{
    point p1(10,20);
    cout<<endl<<"point = ";
    p1.print();
    cout<<endl;
    point lr(19,1);
    point ul(1,19);
    rect myRect(&ul, &lr);
    myRect.print();

    return 0;
}

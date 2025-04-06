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
    point ul;
    point lr;
public:
    point getxul()
    {
        return ul;
    }
    point getlr()
    {
        return lr;
    }
    void setul(point _ul)
    {
        ul=_ul;
    }
        void setlr(point _lr)
    {
        lr=_lr;
    }
    void setlr(int x , int y)
    {
        lr.setx (x);
        lr.sety (y);
    }
    void setul(int x , int y)
    {
        ul.setx(x);
        ul.sety(y);
    }
    rect(point _ul,point _lr)
    {
         ul=_ul;
         lr=_lr;
    }
    rect(int x1, int y1, int x2, int y2)
    {
    ul.setx(x2);
    ul.sety(y2);
    lr.setx(x1);
    lr.sety(y1);
    }
    void print()
    {
        cout<<"("<<lr.getx()<<","<<lr.gety()<<")";
        cout<<"("<<ul.getx()<<","<<ul.gety()<<")";
    }
    ~ rect()
    {
        cout<<"\n\nrect destructor";
    }
};

class circle
{
    int r;
    point center;
public:
        int getr()
    {
        return r ;
    }
        void setr(int _r)
    {
        r=_r;
    }
        point getcenter()
    {
        return center ;
    }
    void setcenter(int _center)
    {
        center=_center;
    }
    void setcenter(point _center)
    {
        center=_center;
    }
    void setcenter(int x , int y)
    {
        center.setx(x);
        center.sety(y);
    }
    circle(int _r=0,int x1=0,int y1=0)
    {
    r=_r;
    center.setx(x1);
    center.sety(y1);
    }
    void print()
    {
        cout<<"radius and center point ="<<r;
        cout<<"("<<center.getx()<<","<<center.gety()<<")";
    }
    ~ circle()
    {
        cout<<"\n\ncircle destructor";
    }
};

int main()
{
    point p1(10,20);
    cout<<endl<<"point = ";
    p1.print();
    cout<<endl<<"rectangle = ";
    rect r1(10,20,40,50);
    r1.print();
    cout<<endl<<"circle ";
    circle c1(10);
    c1.print();
    return 0;
}

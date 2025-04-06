#include <iostream>
using namespace std;

class shape
{
protected:
    int dim1;
    int dim2;
public:
    virtual void setdim1(int _dim1)
    {
        dim1=_dim1;
    }
    virtual void setdim2(int _dim2)
    {
        dim2=_dim2;
    }
    shape(int _dim1,int _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    shape(int _dim1)
    {
        dim1=_dim1;
        dim2=0;
    }
    shape()
    {
        dim1=dim2=0;
    }
    virtual int area()=0;
};

class rect : public shape
{
public:
    rect(int _dim1,int _dim2):shape(_dim1,_dim2){}
    rect(int _dim1):shape(_dim1)
    {
        dim1=_dim1;
        dim2=0;
    }
    int area()
    {
        return dim1*dim2;
    }
};

class square : public rect
{
public:
    void setdim1(int _dim1)
    {
        dim1=dim2=_dim1;
    }
    void setdim2(int _dim1)
    {
        dim1=dim2=_dim1;
    }
    square(int _dim1):rect(_dim1){}
    int area()
    {
        return dim1*dim1;
    }
};

class tri : public shape
{
public:
    tri(int _dim1,int _dim2):shape(_dim1,_dim2){}
    int area()
    {
        return 0.5*dim1*dim2;
    }
};

class circle : public shape
{
public:
    void setdim1(int _dim1)
    {
        dim1=dim2=_dim1;
    }
    void setdim2(int _dim1)
    {
        dim1=dim2=_dim1;
    }
    circle(int _dim1):shape(_dim1){}
    int area()
    {
        return (22/7)*dim1*dim1;
    }
};

int sumarea(shape *arr[],int x)
{
    int sum=0;
    int i;
    for (i=0;i<x;i++)
    {
        sum+=arr[i]->area();
    }
            return sum;
}
int main()
{
    rect r1(2,4);
    shape *ptr1=&r1;
    cout<<"Area of rectangele = "<<ptr1->area()<<endl;
    tri t1(10,2);
    shape *ptr2=&t1;
    cout<<"Area of triangle = "<<ptr2->area()<<endl;
    circle c1(3);
    shape *ptr3=&c1;
    cout<<"Area of circle = "<<ptr3->area()<<endl;
    square s1(2);
    shape *ptr4=&s1;
    cout<<"Area of square = "<<ptr4->area()<<endl;
    shape *arr[4]={&s1,&t1,&c1,&r1};
    int x = sumarea(arr,4);
    cout<<endl<<"summation area = "<<x;
    return 0;
}

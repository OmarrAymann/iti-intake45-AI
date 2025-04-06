#include <iostream>

using namespace std;

class stack
{
    int* arr;
    int size;
    int tos;
public:
    stack()
    {
        size = 3;
        tos = -1;
        arr = new int [size];
    }
    stack(int _size)
    {
        size =_size;
        tos=-1;
        arr = new int [size];
    }
    void push (int value)
    {
        if(tos<size-1)
            {
                tos++;
                arr[tos]=value;
            }
        else
            cout<<"the stack is full";
    }
    int pop(int& value)
    {
        if(tos != -1)
        {
            value =arr[tos];
            tos--;
            return 1;
        }
        else
        {
            cout<<"the stack is empty";
         return 0;
        }
    }
    stack(stack& s)
    {
        tos=s.tos;
        size=s.size;
        arr=new int [size];
        for (int i=0;i<=tos;i++)
        {
            arr[i]=s.arr[i];
        }
    }

    ~stack()
    {
        cout<<"\n destructor";
        delete[]arr;
    }
};

int main()
{
    stack s1(5);
    int x;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<endl;
    s1.pop(x);
    s1.pop(x);
    s1.pop(x);
    s1.pop(x);
    cout<<endl;
    cout<<x;

    return 0;
}

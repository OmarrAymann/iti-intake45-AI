#include <iostream>

using namespace std;

class stack
{
    int arr[3];
    int size;
    int tos;
public:
    stack()
    {
        size = 3;
        tos = -1;
        int x ;
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

};

int main()
{
    stack s1;
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

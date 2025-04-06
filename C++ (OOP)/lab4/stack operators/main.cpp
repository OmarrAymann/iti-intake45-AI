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

    stack operator= (const stack& s) //delete old array before create new one
    {
        tos=s.tos;
        size=s.size;
        delete [] arr;
        arr=new int [size];
        for (int i=0;i<=tos;i++)
        {
            arr[i]=s.arr[i];
        }
        return *this;
    }
    stack operator+ (const stack& s)
    {
        stack result;
        result.size = size + s.size;
        result.tos = tos + s.tos+1;
        for (int i=0;i<=tos;i++)
        {
            result.arr[i] = arr[i];
        }
        for (int j=0;j<=s.tos;j++)
        {
            result.arr[tos+1+j] = s.arr[j];
        }
        return result;
    }
    ~stack()
    {
        //cout<<"\n destructor\n";
        delete[]arr;
    }
    friend void display(stack s);
};

void display(stack s)
{
    for(int i=0;i<s.tos+1;i++)
        cout<<endl<<"the stack :"<<"["<<s.arr[i]<<"]";
}

int main()
{
    stack s1(5);
    stack s2(5);
    stack s3;
    {
        stack s4;
    }
    int x;
    s1.push(1);
    s1.push(2);
    s2.push(1);
    s2.push(2);
    s1.push(3);
    s1.push(4);
    cout<<endl;
    s1.pop(x);
    cout<<"pop value = "<<x<<endl<<"s1 :";
    display(s1);
    cout<<endl<<"s2 :";
    display(s2);
    s3=s1+s2;
    cout<<endl<<"s3 :";
    display(s3);
    s1=s2;
    cout<<endl<<"new s1 :";
    display(s1);
    return 0;
}

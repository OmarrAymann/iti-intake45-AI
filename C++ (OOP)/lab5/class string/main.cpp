#include <iostream>
#include <cstring>
using namespace std;

class STRING
{
    int size;
    char* arr;
public:
    STRING()
    {
        size = 10;
        arr = new char [size];
    }
    STRING(int _size)
    {
        size =_size;
        arr = new char [size];
    }
        STRING(char _arr[])
    {
        size =strlen(_arr)+10;
        arr = new char [size];
        arr = strcpy(arr , _arr);
    }

    STRING(const STRING& s) //copy ctor
    {
        size=s.size;
        arr=new char [size];
        strcpy(arr , s.arr);
    }
        STRING operator= (const STRING& s) //delete old array before create new one
    {
        size=s.size;
        delete [] arr;
        arr = new char [size];
        strcpy(arr , s.arr);
        return *this;
    }
    STRING operator+ (const STRING& s)
    {
        STRING result;
        int newsize=strlen(arr)+strlen(s.arr);
        char* newarr = new char[newsize + 1];
        strcpy(newarr , arr);
        strcat(newarr, s.arr);
        result.size=newsize;
        result.arr=newarr;
        return result;
    }
    void display()
    {
        cout<<endl;
    for(int i=0;i<size;i++)
    {
           cout<<arr[i];
    }

    }
    ~STRING()
    {
        //cout<<"\nDestructor";
        delete[]arr;
    }
};

int main()
{
STRING s1("omar");
STRING s2(" ayman");
STRING s3;
s3=s1+s2;
s3.display();

    return 0;
}

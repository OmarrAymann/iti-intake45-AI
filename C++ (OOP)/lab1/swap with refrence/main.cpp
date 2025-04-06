#include <iostream>

using namespace std;
void swap(int& x ,int& y)
{
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a = 100 , b= 500 ;
    swap(a,b);
    cout<< "a =" <<a<<endl<<"b ="<<b ;
    return 0;
}

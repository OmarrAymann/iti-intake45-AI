#include <iostream>

using namespace std;
struct emp
{
    int id ;
    char name[30];
    int age ;
};
int main()
{
    emp e1 ;
    cout<<("please enter the id : ");
    cin>> e1.id;
    cout<<("please enter the name:");
    cin>> e1.name;
    cout<<("please enter the age :");
    cin>> e1.age;
    cout<<"the id :"<<e1.id<<endl<<"the name :"<<e1.name<<endl<<"the age :"<<e1.age;
    return 0;
}

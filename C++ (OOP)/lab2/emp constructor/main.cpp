#include <iostream>
# include <string.h>
using namespace std;
class emp
{

    int id ;
    int age ;
    char name[30];

    public :
    int getid()
    {
        return id ;
    }
    int getage()
    {
        return age ;
    }
    char* getname()
    {
        return name ;
    }
    void setid(int _id)
    {
        id=_id;
    }
    void setage(int _age)
    {
        age=_age;
    }
    void setname(char* _name)
    {
        strcpy(name,_name);
    }

    emp (int _id, int _age ,char _name[])
    {
        id=_id;
        age=_age;
        strcpy(name,_name);
    }
    emp (int _id, int _age)
    {
        id=_id;
        age=_age;
        strcpy(name,"no name");
    }
    emp (int _id)
    {
        id=_id;
        age=000;
        strcpy(name,"no name");
    }
    emp ()
    {
        id=000;
        age=000;
        strcpy(name,"no name");
    }
void print()
{
    cout<<"the id :"<<id<<endl<<"the age :"<<age<<endl<<"the name :"<<name;
}
~emp()
    {
        cout<<"\ndestructor";
    }

};


int main()
{
    int id , age;
    char name [30];
    emp e1;
    emp e2(122);
    emp e3(155,18);
    emp e4(168,156,"omar");
    emp e5;
    cout<<("please enter the id : ");
    cin>>id;
    cout<<("please enter the age:");
    cin>>age;
    cout<<("please enter the name :");
    cin>>name;
    e5.setid(id);
    e5.setage(age);
    e5.setname(name);
    e1.print();
    cout<<endl;
    e2.print();
    cout<<endl;
    e3.print();
    cout<<endl;
    e4.print();
    cout<<endl;
    e5.print();
    return 0;
}

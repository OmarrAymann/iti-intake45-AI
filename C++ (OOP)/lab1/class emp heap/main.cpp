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
};

int main()
{
    int id , age ;
    char name [30];
    emp e1 ;
    emp* ptr=new emp;
    cout<<("please enter the id : ");
    cin>>id;
    cout<<("please enter the age:");
    cin>>age;
    cout<<("please enter the name :");
    cin>>name;
    ptr->setid(id);
    ptr->setage(age);
    ptr->setname(name);
    cout<<"the id :"<<ptr->getid()<<endl<<"the age :"<<ptr->getage()<<endl<<"the name :"<<ptr->getname();
    return 0;
}

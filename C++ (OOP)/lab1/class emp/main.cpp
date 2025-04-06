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
    cout<<("please enter the id : ");
    cin>>id;
    cout<<("please enter the age:");
    cin>>age;
    cout<<("please enter the name :");
    cin>>name;
    e1.setid(id);
    e1.setage(age);
    e1.setname(name);
    cout<<"the id :"<<e1.getid()<<endl<<"the age :"<<e1.getage()<<endl<<"the name :"<<e1.getname();
    return 0;
}

#include <iostream>
#include<cstring>
using namespace std;

class person
{
protected:
    int id;
    int age;
    char name [30];
public:
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
    int getid()
    {
        return id;
    }
    int getage()
    {
        return age;
    }
    char* getname()
    {
        return name;
    }
    void print()
    {
        cout<<"\nperson data: id :"<<id<<" ,age :"<<age<<" ,name :"<<name;
    }
    person(int _id=0,int _age=0,char* _name={"no name"})
    {
        id=_id;
        age=_age;
        strcpy(name,_name);
    }
    ~person()
    {
        cout<<"\nperson destructor\n\n";
    }
};

class student : public person
{
    int grade ;
public:
    void setgrade(int _grade)
    {
        grade=_grade;
    }
        int getgrade()
    {
        return grade;
    }
    void printstudent()
    {
        person::print();
        cout<<"\nstudent data : grade :"<<grade;
    }
        student(int _id,int _age,char* _name,int _grade=99):person(_id,_age,_name)
    {
        grade=_grade;
    }
    ~student()
    {
        cout<<"\n\nstudent destructor";
    }
};

class emp : public person
{
    int salary;

public :

    void setsalary(int _salary)
    {
        salary=_salary;
    }
    int getsalary()
    {
        return salary;
    }
    void printemp()
    {
        person::print();
        cout<<"\nemploy data : salary :"<<salary;
    }
    emp(int _id,int _age,char* _name,int _salary=3000):person(_id,_age,_name)
    {
        salary=_salary;
    }
    ~emp()
    {
        cout<<"\nemp destructor";
    }
};
int main()
{
    person p1;
    p1.print();
    cout<<endl<<endl;
    emp e1(155,33,"mohamed",9000);
    e1.printemp();
    cout<<endl<<endl;
    student s1(999,16,"ahmed",99);
    s1.printstudent();
    return 0;
}

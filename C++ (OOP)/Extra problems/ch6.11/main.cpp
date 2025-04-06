#include <iostream>
# include <string.h>
using namespace std;
class fraction
{

    int num; //numerator
    int den; //denominator

    public :
    int getnum()
    {
        return num ;
    }
    int getden()
    {
        return den ;
    }
    void setnum(int _num)
    {
        num=_num;
    }
    void setden(int _den)
    {
        den=_den;
    }
    fraction (int _num, int _den)
    {
        num=_num;
        den=_den;
    }
    fraction (int _num)
    {
        num=_num;
        den=1;
    }
    fraction ()
    {
        num=0;
        den=1;
    }
    void print()
    {
    if (num == 0 && den==0)
        cout<<"Math error";
    else if (den == 0)
        cout<<"Math error";
    else if (num == 0)
        cout<<"0";
    else if (num == den)
        cout<<"1";
    else if (den == 1)
        cout<<num;
    else
        cout<<num<<"/"<<den;
    }
    fraction operator+ (fraction f)
    {
        fraction result;
        int i;
        result.num = num*f.den + den*f.num;
        result.den = den * f.den;
        for(i=result.num ;i>0 ;i--)
        {
            if (result.num%i==0 && result.den%i==0)
            {
                result.num= result.num / i;
                result.den= result.den / i;
                break;
            }
        }
        return result;
    }
    fraction operator- (fraction f)
    {
        fraction result;
        result.num = num*f.den - den*f.num;
        result.den = den * f.den;
        for(int i=result.num ;i>0 ;i--)
        {
            if (result.num%i==0 && result.den%i==0)
            {
                result.num= result.num / i;
                result.den= result.den / i;
                break;
            }
        }
        return result;
    }
    fraction operator* (fraction f)
    {
        fraction result;
        result.num = num * f.num;
        result.den = den * f.den;
        for(int i=result.num ;i>0 ;i--)
        {
            if (result.num%i==0 && result.den%i==0)
            {
                result.num= result.num / i;
                result.den= result.den / i;
                break;
            }
        }
        return result;
    }
    fraction operator/ (fraction f)
    {
        fraction result;
        result.num = num * f.den;
        result.den = den * f.num;
        for(int i=result.num ;i>0 ;i--)
        {
            if (result.num%i==0 && result.den%i==0)
            {
                result.num= result.num / i;
                result.den= result.den / i;
                break;
            }
        }
        return result;
    }
    explicit operator float()
    {
        return (float) (num)/den;
    }
};

int main()
{
    int num;
    int den;
    fraction f1;
    fraction f2;
    fraction f3;
    cout<<("please enter first the numerator number : ");
    cin>>num;
    cout<<("please enter first the  denominator number : ");
    cin>>den;
    f1.setnum(num);
    f1.setden(den);
    cout<<("\n");
    cout<<("please enter second the numerator number : ");
    cin>>num;
    cout<<("please enter second the  denominator number : ");
    cin>>den;
    f2.setnum(num);
    f2.setden(den);
    cout<<endl<<"Summation :";
    f3=f1+f2;
    f3.print();
    cout<<endl<<"Subtraction :";
    f3=f1-f2;
    f3.print();
    cout<<endl<<"Multiplication :";
    f3=f1*f2;
    f3.print();
    cout<<endl<<"Division :";
    f3=f1/f2;
    f3.print();
    cout<<endl;
    float Float = (float)f3;
    cout<<"the division = "<<Float;
    return 0;
}


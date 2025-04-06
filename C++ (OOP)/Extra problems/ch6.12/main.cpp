#include <iostream>
using namespace std;

class fraction
{
    int num;
    int den;

public:
    int getnum()
    {
        return num;
    }

    int getden()
    {
        return den;
    }

    void setnum(int _num)
    {
        num = _num;
    }

    void setden(int _den)
    {
        den = _den;
    }

    fraction(int _num, int _den)
    {
        num = _num;
        den = _den;
    }

    fraction(int _num)
    {
        num = _num;
        den = 1;
    }

    fraction()
    {
        num = 0;
        den = 1;
    }

    void print()
    {
        if (num == 0 && den == 0)
            cout << "Math error";
        else if (den == 0)
            cout << "Math error";
        else if (num == 0)
            cout << "0";
        else if (num == den)
            cout << "1";
        else if (den == 1)
            cout << num;
        else
            cout << num << "/" << den;
    }

    fraction multiply(fraction f)
    {
        int new_num = num * f.num;
        int new_den = den * f.den;
        fraction result(new_num, new_den);
        return result;
    }

    void output()
    {
        print();
    }
};

int main()
{
    int denominator;
    cout << "enter your fraction : ";
    cin >> denominator;

    fraction fractions[denominator];
    for(int i =1;i<=denominator;i++)
    {
        fractions[i-1]=fraction(i,denominator);
    }

    for(int i= 0; i<denominator;i++)
    {
        fractions[i].output();
        if (i != denominator - 1)
            cout << "     ";
    }
    cout<<endl<<endl;
    for(int i=0;i<denominator;i++)
    {
        for (int j=0; j<denominator;j++)
        {
            fraction result = fractions[i].multiply(fractions[j]);
            result.output();
            if (j != denominator - 1)
                cout << "     ";
        }
        cout << endl;
    }

    return 0;
}

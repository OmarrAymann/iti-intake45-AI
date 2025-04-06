#include <iostream>
using namespace std;
class Int {
    int i;
public:

    Int()
    {
        i=0;
    }
    Int(int _i)
    {
     i=_i;
     }
    void display()
    {
        cout << i;
    }
    void add(Int i2, Int i3)
    {
        i= i2.i + i3.i;
    }
};

int main() {
    Int i;
    Int i1(10);
    Int i2(20);
    i.add(i2,i1);
    cout << "summation = ";
    i.display();
    cout << endl;

    return 0;
}

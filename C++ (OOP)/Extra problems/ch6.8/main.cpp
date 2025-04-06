#include <iostream>
using namespace std;

class SerialNumber
{
    int serialNumber;
    static int objectCount;

public:
    SerialNumber()
    {
        objectCount++;
        serialNumber = objectCount;
    }
    void count_obj()
    {
        cout << "i'm object number : " << serialNumber << endl;
    }

    static int getObjectCount()
    {
        return objectCount;
    }
};

int SerialNumber::objectCount = 0;

int main()
{
    SerialNumber obj1;
    SerialNumber obj2;
    SerialNumber obj3;

    obj1.count_obj();
    obj2.count_obj();
    obj3.count_obj();

    return 0;
}

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Ship
{
    static int objectCount;
    int serialNumber;
    int degree;
    float minutes;
    char direction;

public:
    Ship()
    {
        objectCount++;
        serialNumber = objectCount;
        degree=0;
        minutes= 0.0;
        direction = 'n';
    }
    void getPosition()
    {
        cout<<"enter the ship's position :\n";
        cout<<"enter degree: ";
        cin>>degree;
        cout<<"enter minutes : ";
        cin>>minutes;
        cout<<"enter direction (N,S,E,W) : ";
        cin>>direction;
        direction = toupper(direction);
        if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W')
            {
                cout << "try again wrong direction" << endl;
                degree = 0;
                minutes = 0.0;
                direction = 'N';
            }
        else if (degree < 0 || degree > 180)
            {
                cout << "try again wrong degree" << endl;
                degree = 0;
                minutes = 0.0;
                direction = 'N';
            }
        else if (minutes < 0.0 || minutes >= 60.0)
            {
                cout << "try again wrong minutes" << endl;
                degree= 0;
                minutes = 0.0;
                direction = 'N';
            }
    }
    void reportPosition()
    {
        cout<<"ship number : "<<serialNumber<<endl;
        cout<<"position of ship "<<degree<<'\xF8'<<minutes<<"'"<<direction;
    }
    static int getObjectCount()
    {
        return objectCount;
    }
};
int Ship::objectCount = 0;

int main()
 {
    Ship ship1;
    Ship ship2;
    cout << "\nEnter details for Ship 1:\n";
    ship1.getPosition();
    cout << "\nEnter details for Ship 2:\n";
    ship2.getPosition();
    cout << "\nShip 1 details:\n";
    ship1.reportPosition();
    cout << "Ship 2 details:\n";
    ship2.reportPosition();

    return 0;
}

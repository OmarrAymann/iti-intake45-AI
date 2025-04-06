#include <iostream>
#include <iomanip>
using namespace std;

class Angle
{
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int _deg, float _min, char _dir)
    {
         degrees=_deg;
         minutes=_min;
         direction=_dir;
    }
    Angle()
    {
        degrees=0;
        minutes=0.0;
        direction='N';
    }
    void getAngle()
    {
    cout << "enter degrees: ";
    cin >> degrees;
    cout << "enter minutes: ";
    cin >> minutes;
    cout << "enter direction (N, S, E, W): ";
    cin >> direction;

    direction = toupper(direction);
    if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W')
        {
            cout << "try again wrong direction" << endl;
            degrees = 0;
            minutes = 0.0;
            direction = 'N';
        }
    else if (degrees < 0 || degrees > 180)
        {
            cout << "try again wrong degree" << endl;
            degrees = 0;
            minutes = 0.0;
            direction = 'N';
        }
    else if (minutes < 0.0 || minutes >= 60.0)
        {
            cout << "try again wrong minutes" << endl;
            degrees = 0;
            minutes = 0.0;
            direction = 'N';
        }
    }
    void display()
    {
        cout<<degrees<<'\xF8'<<minutes<<"'"<<direction<<endl;
    }
};
int main()
{
    Angle a1(149, 34.8, 'W');
    cout << "defult angle: ";
    a1.display();
    while (true)
    {
    Angle a2;
    cout << "\nEnter a new angle:\n";
    a2.getAngle();
    cout << "You entered: ";
    a2.display();
    }

    return 0;
}

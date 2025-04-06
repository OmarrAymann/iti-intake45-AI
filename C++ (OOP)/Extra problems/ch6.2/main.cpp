#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class tollBooth {
    int totalCars;
    double totalCash;

public:

    tollBooth()
    {
        totalCars=0;
        totalCash=0.0;
    }
    void payingcar()
    {
        ++totalCars;
        totalCash += 0.50;
    }
    void didnotpaycar()
    {
        ++totalCars;
    }
    void display()
    {
        cout << "total cars: " << totalCars << endl;
        cout << "total cash: $" << totalCash << endl;
    }
};

int main() {
    tollBooth car;
    char input;
    int counter=0;
    while (true)
        {
            cout<<"passing cars :"<<counter<<endl;
            cout << "press 'p' for a paying car\n";
            cout << "'n' for a non-paying car\n";
            cout << "'Esc' to exit \n";
            input = _getch();
            if (input == 27)
                {
                    cout << "byeee \n";
                    system("cls");
                    car.display();
                    break;
                }
            else if (input == 'P')
                {
                    car.payingcar();
                    system("cls");
                    counter+=1;
                    cout << "paying car recorded \n";

                }
            else if (input == 'n')
                {
                    car.didnotpaycar();
                    system("cls");
                    counter+=1;
                    cout << "non paying car recorded \n";
                }
            else
                {
                    system("cls");
                    cout << "try again";
                }
        }
    return 0;
}

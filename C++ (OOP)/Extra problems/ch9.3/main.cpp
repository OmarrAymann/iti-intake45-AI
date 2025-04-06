#include <iostream>
#include <string>
#include <limits>
using namespace std;

class publication
{
    string title;
    float price;

public:
    void getdata()
    {
        cout<<"enter title : ";
        cin>>title;
        while (true)
        {
            cout<<"enter price: ";
            cin>>price;
            if (price > 0)
                break;
            else
                cout << "try again" << endl;
        }
    }
    void putdata()
    {
        cout << "\nTitle: " << title;
        cout << "\nPrice: " << price;
    }
};

class sales
{
    float sales[3];
public:
    void getdata()
    {
        for (int i = 0; i < 3; i++)
        {
            while (true)
            {
                cout << "Month " << i + 1 << ": ";
                cin >> sales[i];
                if (sales[i] >= 0)
                    break;
                else
                    cout << "try again" << endl;
            }
        }
    }

    void putdata()
    {
        for (int i = 0; i < 3; i++)
        {
            cout<<sales[i]<<" dollars ";
        }
    }
};

class book : private publication, private sales
{
private:
    int pages;

public:
    void getdata()
    {
        publication::getdata();
        while (true)
        {
            cout<<"enter number of pages: ";
            cin>>pages;
            if (pages > 0)
                break;
            else
                cout << "try again" << endl;
        }
    }
    void putdata()
    {
        publication::putdata();
        sales::putdata();
        cout << "\nPages: " << pages;
    }
};

class tape : private publication, private sales
{
private:
    float time;

public:
    void getdata()
    {
        publication::getdata();
        while (true)
        {
            cout<<"enter playing time: ";
            cin>>time;
            if(time >0)
                break;
            else
                cout<<"try again"<<endl;
        }
    }
    void putdata()
    {
        publication::putdata();
        sales::putdata();
        cout << "\nPlaying time: " << time;
    }
};

int main()
{
    book b1;
    tape t1;

    cout<<"enter data for book:\n";
    b1.getdata();
    cout<<"enter data for tape:\n";
    t1.getdata();
    cout<<"\nbok details:\n";
    b1.putdata();
    cout<<"\n tape details:\n";
    t1.putdata();
    cout << endl;
    return 0;
}

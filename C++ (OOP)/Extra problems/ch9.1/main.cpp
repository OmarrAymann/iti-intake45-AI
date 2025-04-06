#include <iostream>
#include <string>
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
        cout << "\ntitle: " << title;
        cout << "\nPrice: " << price;
    }
};

class book : private publication
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
        cout<<"\npages : "<<pages;
    }
};

class tape : private publication
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
        cout<<"\nPlaying time : "<<time<<" second";
    }
};

int main()
{
    book b1;
    tape t1;
    cout<<"book details : "<<endl;
    b1.getdata();
    cout<<"tape details : "<<endl;
    t1.getdata();
    b1.putdata();
    t1.putdata();
    return 0;
}

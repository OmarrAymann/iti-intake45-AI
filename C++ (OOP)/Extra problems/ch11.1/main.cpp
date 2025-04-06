#include <iostream>
#include <string>
using namespace std;

class publication
{
protected:
    string title;
    float price;

public:
    virtual void putdata()
    {
        cout<<"title: "<<title<<endl;
        cout<<"price: "<<price<<endl;
    }
    virtual void getdata()
    {
        cout << "enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "enter price: ";
        cin >> price;
    }
    virtual ~publication()
    {
        cout<<"destructor";
    }
};

class book : public publication
{
private:
    int page_count;

public:
    void getdata()
    {
        publication::getdata();
        cout << "enter page count: ";
        cin >> page_count;
    }

    void putdata()
    {
        publication::putdata();
        cout << "page count: " << page_count << endl;
    }
};

class tape : public publication
{
private:
    float playing_time;

public:
    void getdata()
    {
        publication::getdata();
        cout << "enter playing time : ";
        cin >> playing_time;
    }

    void putdata()
    {
        publication::putdata();
        cout << "playing time: " << playing_time << " second" << endl;
    }
};

int main()
{
    const int max_pubs = 100;
    publication* pubarr[max_pubs];
    int count = 0;
    char choice;

    while (true)
        {
        if (count >= max_pubs)
        {
            cout << "max publications reached." << endl;
            break;
        }

        cout << " book (b)"<<endl;
        cout<<" tape (t)"<<endl;
        cout<< " exit (e): "<<endl;
        cin >> choice;

        if (choice == 'e')
            break;

        if (choice == 'b') {
            pubarr[count] = new book();
        } else if (choice == 't') {
            pubarr[count] = new tape();
        } else {
            cout << "try again" << endl;
            continue;
        }

        pubarr[count]->getdata();
        count++;
    }

    cout << "\ndata:\n";
    for (int j = 0; j < count; j++)
        {
            pubarr[j]->putdata();
            cout << endl;
        }

    for (int j = 0; j < count; j++)
        {
            delete pubarr[j];
        }

    return 0;
}

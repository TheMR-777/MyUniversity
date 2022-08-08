#include <iostream>
using namespace std;

class Profile
{
    string f_n;
    string l_n;
    int age;

public:

    // Custom Constructor

    Profile(string f, string l, int a)
        : f_n(f), l_n(l), age(a)
    {
        cout << "Constructor Called!" << endl;
    }

    // Copy Constructor

    Profile(const Profile& other_p)
    {
        cout << "Copy Constructor Called!" << endl;
        f_n = other_p.f_n;
        l_n = other_p.l_n;
        age = other_p.age;
    }


    void Print()
    {
        cout << "Name : " << f_n + l_n << endl;
        cout << "Age  : " << age << endl;
    }
};



int main()
{
    Profile MR("Mr.", " Blue", 19);
    Profile Other_Me = MR;

    cout << endl;
    Other_Me.Print();
}
#include <iostream> 
#include <vector>
using namespace std;


class Profile
{
    public:
        string f_name;
        string l_name;

        Profile( string &f , string &l )
        {
            f_name = f;
            l_name = l;
        }
};




int main()
{
    // Initialization

        string f , l;

    // Introduction

        system("cls");
        cout << endl;
        cout << " +----------------------------------------------------+" << endl;
        cout << " | It's a Program, which uses Class to store string   |" << endl;
        cout << " | values in the Profile of the User (which is U BTW) |" << endl;
        cout << " +----------------------------------------------------+" << endl;
        cout << " | Now this Program uses User Defined Constructor to  |" << endl;
        cout << " | store the First and Last name of yours. Always     |" << endl;
        cout << " | remember to create the Constructor inside of the   |" << endl;
        cout << " | Class you created (inside of the Public specifier) |" << endl;
        cout << " +----------------------------------------------------+" << endl;
        cout << endl;

    // Taking Input

        cout << " - Enter your First Name : ";
        cin >> f;

        cout << " - Enter your Last Name : ";
        cin >> l;

        Profile Me ( f , l );

    // Output

        cout << endl;
        cout << "Here is the Full Name : " << Me.f_name << " " << Me.l_name << endl;
        cout << endl;
}
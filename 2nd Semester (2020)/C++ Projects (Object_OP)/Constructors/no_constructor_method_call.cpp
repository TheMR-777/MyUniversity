#include <iostream> 
#include <vector>
using namespace std;


class Profile
{
    public:
        string f_name;
        string l_name;

        void set( string &f , string &l )
        {
            f_name = f;
            l_name = l;
        }
};




int main()
{
    // Initialization

        string f , l;
        Profile Me;

    // Introduction

        system("cls");
        cout << endl;
        cout << " +----------------------------------------------------+" << endl;
        cout << " | It's a Program, which uses Class to store string   |" << endl;
        cout << " | values in the Profile of the User (which is U BTW) |" << endl;
        cout << " +----------------------------------------------------+" << endl;
        cout << " | Now this Program uses User Defined Function inside |" << endl;
        cout << " | the class. OR in C++ Lang., a Method Function to   |" << endl;
        cout << " | do the same with a Method Call, which the Custom / |" << endl;
        cout << " | User Defined Constructor does. Just an Example     |" << endl;
        cout << " +----------------------------------------------------+" << endl;
        cout << endl;

    // Taking Input

        cout << " - Enter your First Name : ";
        cin >> f;

        cout << " - Enter your Last Name : ";
        cin >> l;

        Me.set( f , l );

    // Output

        cout << endl;
        cout << "Here is the Full Name : " << Me.f_name << " " << Me.l_name << endl;
        cout << endl;
}
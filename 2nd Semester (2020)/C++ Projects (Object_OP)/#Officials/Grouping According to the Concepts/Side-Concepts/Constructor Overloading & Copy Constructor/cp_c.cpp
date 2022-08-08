#include <iostream>
using namespace std;

class Profile
{
    string f_n;
    string l_n;
    int age;

    public:

    // Custom Constructor

        Profile ( string f , string l , int a )
            : f_n(f) , l_n(l) , age(a) 
        { 
            cout << "Constructor Called!" << endl; 
        }

    // Copy Constructor

        Profile ( const Profile &other_p )
        {
            cout << "Copy Constructor Called!" << endl;
            memcpy( this , &other_p , sizeof(Profile) );
        }

        void Print()
        {
            cout << "Name : " << f_n + l_n << endl;
            cout << "Age  : " << age << endl;
        }
};



int main()
{
    Profile MR ( "MR" , "_777" , 19 );
    Profile Other_Me = MR;

    Other_Me.Print();
}
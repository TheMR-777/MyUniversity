#include <iostream> 
using namespace std;

class Profile
{
    string first_n;
    string last_n;
    short age;

    public:

        Profile()
        {
            cout << "Default Constructor Called!" << endl;
        }

        Profile(string f , string l , short a)
        {
            cout << "Custom Constructor Called!" << endl;
            first_n = f;
            last_n = l;
            age = a;

            cout << "My First Name : " << first_n << endl;
            cout << "My Last Name  : " << last_n << endl;
            cout << "My AGE        : " << age << endl;
            cout << endl;
        }

        ~Profile()
        {
            cout << "Destructor Called for " << first_n << " " << last_n <<  endl;
        }
};

int main()
{
    Profile Ayyub ( "Ayyub" , "Jutt" , 20 );
    Profile Saif ( "Muhammad" , "Saif" , 19 );
    Profile Hammad ( "Hammad" , "Shouqat" , 20 );
    Profile Ali ( "Ali" , "Hassan" , 19 );
}
#include <iostream> 
using namespace std;


class Profile
{
private:
    string f_name;
    string l_name;
    int age;

public:

    string first_Name()
    {
        return f_name;
    }

    string last_Name()
    {
        return l_name;
    }
    
    string full_Name()
    {
        return ( f_name + " " + l_name );
    }

    int show_age()
    {
        return age;
    }


    Profile( string &f , string &l , int &age_t )
    {
        f_name = f;
        l_name = l;
        age = age_t;
    }

    ~Profile()
    {
        cout << "Destructed" << endl;
    }
};




int main()
{

        string f , l; int age;

        f = "Muhammad";
        l = "Usman";
        age = 18;

        Profile Me(f , l , age);
        cout << "First name : " << Me.first_Name() << endl;
        cout << "Last name  : " << Me.last_Name() << endl;
        cout << "Full name  : " << Me.full_Name() << endl;
        cout << "Age        : " << Me.show_age() << endl;

}
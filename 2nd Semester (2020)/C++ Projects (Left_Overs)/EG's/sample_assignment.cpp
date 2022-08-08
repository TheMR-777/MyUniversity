#include <iostream> 
#include <vector>
using namespace std;


class Profile
{
    private:
        string f_name;
        string l_name;
        int age;
    
    public:

        // Functions to display Private content

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

        // Custom Constructors + Overloading & Destructor

        Profile( string f )
        {
            cout << "1st Constructor Called" << endl;
            f_name = f;
        }

        Profile( int age_t )
        {
            cout << "2nd Constructor Called" << endl;
            age = age_t;
        }
        
        Profile( string &f , string &l )
        {
            cout << "3rd Constructor Called" << endl;
            f_name = f;
            l_name = l;
        }

        Profile( string &f , string &l , int &age_t )
        {
            cout << "4th Constructor Called" << endl;
            f_name = f;
            l_name = l;
            age = age_t;
        }

        ~Profile()
        {
            cout << "Destructor Called!" << endl;
        }
};




int main()
{
    // Initialization

        string f , l;
        int age;

    // Input

        f = "John";
        l = "Doe";
        age = 27;
        system("cls");

    // 1st Constructor

        //Profile Me(f);
        //cout << "My First Name : " << Me.first_Name() << endl;

    // 2nd Constructor

        //Profile Me(age);
        //cout << "My age : " << Me.show_age() << endl;

    // 3rd Constructor

        //Profile Me(f , l);
        //cout << "My full name : " << Me.full_Name() << endl;

    // 4th Constructor

       cout<<"output:: using pointers\n";
        Profile *pointer=new Profile(f,l,age);
    // Objects created using pointers    
        cout << "My First Name : " << pointer->first_Name() << endl;
        cout << "My Last Name  : " << pointer->last_Name() << endl;
        cout << "My Full Name  : " << pointer->full_Name() << endl;
        cout << "My AGE        : " << pointer->show_age() << endl;
      
    // Objects created without pointer 
      cout<<"output:: with out pointer\n";s
        
    Profile Me(f , l , age);
     cout << "My First Name : " << Me.first_Name() << endl; 
     cout << "My Last Name  : " << Me.last_Name() << endl;
     cout << "My Full Name  : " << Me.full_Name() << endl;
     cout << "My AGE        : " << Me.show_age() << endl;

}
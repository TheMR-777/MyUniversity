#include <iostream> 
using namespace std;

class Profile
{
    string f_name;
    string l_name;
    int age;

    public:

        // Custom Constructor
        
        Profile( string f , string l , int a )
            : f_name(f) , l_name(l) , age(a)
        {
            cout << "Constructor Called!" << endl;
        }

        // Getter

        void Print()
        {
            cout << endl;
            cout << "My Name : " << f_name << l_name << endl;
            cout << "My AGE  : " << age << endl;
        }
};



int main()
{
    Profile Me( "MR" , "_777" , 19 );
    Me.Print();
}
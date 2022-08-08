#include <iostream>
#include <memory>
using namespace std;

class Profile
{
    string f_name;
    string l_name;
    int age;

    public:

        Profile( string f , string l , int a )
            :f_name(f) , l_name(l) , age(a) {}

        ~Profile()
        {
            cout << "Destructor Called!" << endl;
        }

        string get_name()
        {
            return ( f_name + l_name );
        }
};



int main()
{
    // Initialization

        unique_ptr<Profile> student = make_unique<Profile> ( "MR" , "_777" , 19 );

    // Output for Proof

        // cout << student->get_name() << endl;
        cout << (*student).get_name() << endl;
        cout << "Heap Address    : " << student.get() << endl;
        cout << "Pointer Address : " << &student << endl;
}
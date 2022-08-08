#include <iostream> 
using namespace std;

class Profile
{
    static int my_size;
    string f_name;
    string l_name;
    int age;

    public:
        
    // Static Count

        static int p_size()
        {
            return my_size;
        }

    // Getters

        string get_Full_Name()
        {
            return ( f_name + " " + l_name );
        }

        int get_Age()
        {
            return age;
        }

    // Constructors

        Profile()
        {
            my_size++;
        }

        Profile( string f , string l , int a )
        {
            my_size++;

            f_name = f;
            l_name = l;
            age = a;
        }

    // Destructor

        ~Profile()
        {
            my_size--;
        }
};


// Static Initialization
    
    int Profile::my_size = 0;



int main()
{
    system("cls");
    
    // Initialization

        Profile Me("Muhammad" , "MR" , 19);

    // Getters

        cout << "My Full_Name    : " << Me.get_Full_Name() << endl;
        cout << "My AGE          : " << Me.get_Age() << endl;
        cout << "No. of Profiles : " << Profile::p_size() << endl;

    // Destructing, and watching the results

        cout << endl;
        cout << "After Destruction" << endl;
        Me.~Profile();
        cout << "No. of Profiles : " << Profile::p_size() << endl;
}
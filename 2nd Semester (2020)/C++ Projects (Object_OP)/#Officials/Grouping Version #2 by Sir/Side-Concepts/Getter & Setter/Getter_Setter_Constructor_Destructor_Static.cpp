#include <iostream> 
using namespace std;

class Profile
{
    static int my_size;

    string f_name;
    string l_name;
    int age;

    public:
        
    // Setters
        
        void set_F_Name(string f)
        {
            f_name = f;
        }

        void set_L_Name(string l)
        {
            l_name = l;
        }

        void set_Age(int a)
        {
            age = a;
        }

    // Getters

        string get_F_Name() const
        {
            return f_name;
        }

        string get_L_Name() const
        {
            return l_name;
        }

        string get_Full_Name() const
        {
            return ( f_name + " " + l_name );
        }

        int get_Age() const
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
    
}
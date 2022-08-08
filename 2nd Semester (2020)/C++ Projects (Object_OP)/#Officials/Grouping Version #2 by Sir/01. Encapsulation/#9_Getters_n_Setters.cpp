#include <iostream> 
using namespace std;

class Profile
{

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

        string get_F_Name()
        {
            return f_name;
        }

        string get_L_Name()
        {
            return l_name;
        }

        int get_Age()
        {
            return age;
        }
};



int main()
{
    // Initialization

        Profile My;

    // Setters

        My.set_Age(19);
        My.set_F_Name("Elsa");
        My.set_L_Name("Gray");

    // Getters

        system("cls");
        cout << "My full name : " << My.get_F_Name() << " " << My.get_L_Name() << endl;
        cout << "My AGE       : " << My.get_Age() << endl;
}
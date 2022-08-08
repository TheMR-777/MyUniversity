#include <iostream> 
using namespace std;

class Profile
{
    public:

        string f_name;
        string l_name;
        int age;

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
        My.age = 19;
        My.f_name = "Muhammad";
        My.l_name = "MR";

    // Using Getters

        system("cls");
        cout << "My age : " << My.get_Age() << endl;
        cout << "My Full name : " << My.get_F_Name() << " " << My.get_L_Name() << endl;
}
#include <iostream> 
#include <vector>
using namespace std;

class Profile
{
    public:
        static string f_name;
        static string l_name;
        static int age;

        static void Print()
        {
            cout << "First Name : " << f_name << endl;
            cout << "Last Name  : " << l_name << endl;
            cout << "Age        : " << age << endl;
            cout << endl;
        }
};

int Profile::age;
string Profile::f_name;
string Profile::l_name;

int main()
{
    // Initialization

        system("cls");
        // Profile Me;
        // Profile He;

    // Initializing "Me"

        // Me.age = 19;
        // Me.f_name = "Muhammad";
        // Me.l_name = "MR";
        // Me.Print();

    // Initializing "He"

        // He.age = 20;
        // He.f_name = "Muhammad";
        // He.l_name = "Ahmed";
        // He.Print();

    // Outputting Both

        // Me.Print() ; He.Print();


    // Alternative Way, Initializing a third Person

        Profile::age = 19;
        Profile::f_name = "Muhammad";
        Profile::l_name = "Zubair";
        Profile::Print();
}
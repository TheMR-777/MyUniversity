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
        Profile A;
        Profile B;

    // Initializing "Me"

        // A.age = 19;
        // A.f_name = "The";
        // A.l_name = "MR";
        // A.Print();

    // Initializing "He"

        // B.age = 18;
        // B.f_name = "Elsa";
        // B.l_name = "Gray";
        // B.Print();

    // Outputting Both

        // A.Print() ; B.Print();


    // Alternative Way, Initializing a third Person

        Profile::age = 19;
        Profile::f_name = "Muhammad";
        Profile::l_name = "Zubair";
        Profile::Print();
}
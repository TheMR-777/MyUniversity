#include <iostream> 
#include <vector>
using namespace std;

struct Profile
{
    string f_name;
    string l_name;
    int age;

    void Print()
    {
        cout << "First Name : " << f_name << endl;
        cout << "Last Name  : " << l_name << endl;
        cout << "Age        : " << age << endl;
    }

    Profile(string f , string l , int a)
    {
        f_name = f;
        l_name = l;
        age = a;
    }
};

int main()
{
    // Initialization

        system("cls");
        Profile Me("Muhammad" , "MR" , 19);

    // Output

        Me.Print();
        cout << endl;
}
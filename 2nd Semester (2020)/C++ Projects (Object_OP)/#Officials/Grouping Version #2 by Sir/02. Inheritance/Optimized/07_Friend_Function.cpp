#include <iostream> 
using namespace std;

class Profile
{
    string f_name;
    string l_name;
    string m_Gender;

public:

    // Granting access to the Friend Function

        friend void get_my_friend(Profile& any);

    // Constructor

        Profile(string&& f, string&& l, string&& g)
            : f_name(f), l_name(l), m_Gender(g) {}
};



// Definition of Friend Function

void get_my_friend(Profile& any)
{
    cout << endl;
    cout << "First_Name : " << any.f_name << endl;
    cout << "Last_Name  : " << any.l_name << endl;
    cout << "Gender     : " << any.m_Gender << endl;
}






int main()
{
    // Initialization

        Profile A("Muhammad", "MR", "Male");
        Profile B("Elsa", "Gray", "Female");

    // Priniting by Calling our Friend Function

        get_my_friend(A);
        get_my_friend(B);
}
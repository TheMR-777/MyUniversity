#include <iostream> 
#include <vector>
using namespace std;

class Profile
{
    string f_name;
    string l_name;
    int age;

    public :

    // Granting the Friend Function

        friend void get_my_friend( Profile any );

    // Constructor

        Profile( string f , string l , int a )
        {
            f_name = f;
            l_name = l;
            age = a;
        }
};



// Definition of Friend Function

void get_my_friend( Profile any )
{
    cout << endl;
    cout << "First_Name : " << any.f_name << endl;
    cout << "Last_Name  : " << any.l_name << endl;
    cout << "AGE        : " << any.age << endl;
}






int main()
{
    system("cls");


    // Initialization

        Profile Me("Muhammad" , "MR" , 19);
        Profile Ahmed("Muhammad" , "Ahmed" , 18);

    // Priniting by Calling our Friend Function

        get_my_friend( Me );
        get_my_friend( Ahmed );
}
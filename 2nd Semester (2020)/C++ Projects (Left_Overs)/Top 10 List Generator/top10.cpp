#include <iostream> 
#include <vector>
using namespace std;

class Student
{
    public:
    {
        int ID;
        string name;
        vector<double> Marks;
    }
};

int main()
{
    // Initialization

        string temp;
        vector<string> std;

    // Main Menu

        cout << endl;
        cout << " +-----------------------------------------------------+" << endl;
        cout << " | It's a Result Card, and top 10 List Generator. Only |" << endl;
        cout << " | you have to input is Credentials as asked. I hope U |" << endl;
        cout << " | like my Program. Basically, I've used the OOP here. |" << endl;
        cout << " +-----------------------------------------------------+" << endl;
        cout << " | - Enter Names of the Students as asked, enter \"000\" |" << endl;
        cout << " |   when finished entering Names.                     |" << endl;
        cout << " |-----------------------------------------------------|" << endl;

    // Names Input

        for ( int i=0 ; temp != "000" ; i++ )
        {
            cout << " | Enter Name of Student #" << i+1 << " : " << endl;
            getline(cin, temp);

            if (temp != "000")
            {
                
            }
        }

}
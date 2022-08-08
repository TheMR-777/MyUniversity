#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

int ID(string &pass)
{
    // Getting things ready



    // Main Function

        for ( int i=0 ; i < pass.size() ; i++ )
        {
            if ( pass[i] >= '0' && pass[i] <= '9' )
            {
                
            }
        }
}

int main()
{
    // Initialization

        string pass;

    // Input

        cout << endl;
        cout << "Enter any String : ";
        getline(cin , pass);

    // Output

        cout << "Number of Integers in your String are : " << ID(pass) << endl;
        cout << endl;

    // Finalize

        cin.clear();
        cin.sync(); 
        system("pause");
}
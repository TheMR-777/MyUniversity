#include <iostream> 
#include <vector>
#include <fstream>
using namespace std;


void OUTPUT( const vector<string> &V , const string filename )
{
    // Initialization

        ofstream FILE (filename);

    // Writing Output

        if (FILE.is_open())
        {
            FILE << "The Filename is : " << filename << endl;
            FILE << endl;
            FILE << "The Names U Entered are below" << endl;
            FILE << endl;
            
            for ( int i=0 ; i < V.size() ; i++ )
            {
                FILE << "String #" << i+1 << " is : " << V[i] << endl;
            }

            FILE.close();
        }
        else
        {
            cout << "File cannot be written! Try to run your IDE or .exe file as Admisistrator to fix this problem." << endl;
            cout << endl;
            system("pause");
        }     
}





int main()
{
    // Initialization

        vector<string> V_S;
        string temp;
        string filename;

    // Taking Input

        cout << endl;
        cout << "Enter Any Names in the Vector below (Enter 0 to break the loop) : ";
        cout << endl;

        for (int i=0 ; temp != "0" ; i++)
        {
            cout << "Enter String #" << i+1 << " : ";
            getline(cin , temp);

            if (temp != "0")
            {
                V_S.push_back(temp);
            }
        }
        cout << endl;

        cout << "Enter Name of the Output File" << endl;
        cout << "Name : ";
        cin >> filename;

        filename = filename + ".txt";

    // Function Pass

        OUTPUT( V_S , filename );
}
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    x:
    {
        // Getting External File Name

            string filename;
            cout << endl;
            cout << "It's an External File Reader" << endl;
            cout << "Enter the Name of the File to read: ";
            getline(cin, filename);

        // Creating an Object "TEST" from ifstream

            ifstream TEST (filename);

        // Verifying the Loaded File

            if ( TEST.is_open() )
            {
                cout << "File Successfully Loaded" << endl;
            }
            else
            {
                cout << "404 Not Found." << endl;
                goto x;
            }
            
        // Creating a String to Save Text

            string stest;

        // That's how the Loop is Designed to take every line from External file

            while( getline(TEST, stest) )
            {
                cout << stest << endl;
            }

        // Termination Delay

            system("pause");
    } goto x;
}
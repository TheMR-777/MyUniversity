#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Creating an Object "TEST" from ifstream

        ifstream TEST ("test.txt");

    // Creating a String to Save Text

        string stest;

    // That's how the Loop is Designed to take every line from External file

        while( getline(TEST, stest) )
        {
            cout << stest << endl;
        }
}
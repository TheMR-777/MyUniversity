#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Initialization

        string S;

    // Taking Input

        cout << "Enter String, u wanna write into External File," << endl;
        cout << "Input : ";
        getline(cin, S);

    // File writing Explained

        // Creating an Object (For External File)

            ofstream OUTPUT ("External_File.txt");
            OUTPUT << S;
}
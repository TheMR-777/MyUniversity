#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    // Initialization

        stringstream sss;
        int I;
        string S;


    // Introduction

        system("cls");
        cout << endl;
        cout << "It's a SStream Program, for DATA_TYPE conversion" << endl;
        cout << endl;


    // Input

        cout << "Enter any Integer Value: ";
        cin >> I;


    // Conversion

        sss << I;
        sss >> S;


    // Output

        cout << "Integer Entered: " << I << endl;
        cout << "Converted into String: " << S << endl;
        cout << endl;

        system("pause");


    // Recursive

        main();

}
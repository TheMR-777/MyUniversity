#include <iostream>
#include <array>
using namespace std;

int main()
{
    // Initialization

        array<int, 5> A;
        int sum=0;

    // Introduction

        system("cls");
        cout << "It's the Program of utilizing Standard Templatized Array / STL Array" << endl;
        cout << endl;


    // Taking Input

        cout << "Enter Elements in the STL Array as Asked (Size : 5)" << endl;
        cout << endl;

        for ( int i = 0 ; i < 5 ; i++ )
        {
            cout << "- Enter Elements #" << i+1 << " : ";
            cin >> A[i];
            sum = sum + A[i];
        }
        cout << endl;


    // Outputting the SUM

        cout << "The Sum of Entered Quantities is: " << sum << endl;
        cout << endl;


    // Recursive

        system("pause");
        main();

        

}
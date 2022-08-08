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
        cout << endl;
        cout << " Enter Elements of the STLA as asked" << endl;
        cout << endl;

    // Input

        for ( int i = 0 ; i < A.size() ; i++ )
        {
            cout << "Enter Element #" << i+1 << " : ";
            cin >> A[i];
            sum += A[i];
        }

    // Output

        cout << endl;
        cout << "The SUM is : \t" << sum << endl;
        cout << "The Average is : \t" << sum/A.size() << endl;
        cout << endl;
        system("pause");

    // Recursive

        main();
}
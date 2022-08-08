#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialization

        vector<int> A;
        vector<int> B;
        int size, var;
    

    // Intro
    
        system("cls");
        cout << endl;
        cout << "It's the Relative Element Dealer (Without Function)." << endl;
        cout << "Enter the Elements of two Vectors as asked." << endl;
        cout << endl;


    // Input

        cout << "Enter Size of the Vectors: ";
        cin >> size;

        system("cls");
        cout << endl;
        for ( int i=0 ; i < size ; i++ )
        {
            cout << "Enter Element #" << i+1 << " of 1st Vector : ";
            cin >> var;
            A.push_back(var);
        }

        cout << endl;
        for ( int i=0 ; i < size ; i++ )
        {
            cout << "Enter Element #" << i+1 << " of 2nd Vector : ";
            cin >> var;
            B.push_back(var);
        }


    // Generating Results

        system("cls");
        cout << endl;
        cout << "The SUM of Relative Elements is:" << endl;
        cout << endl;


    // Generating SUM

        for ( int i=0 ; i < size ; i++ )
        {
            cout << "SUM of Element #" << i+1 << " of Vectors: " << A[i] + B[i] << endl;
        }
        cout << endl;
        system("pause");


    // Generating Difference

        system("cls");
        cout << endl;
        cout << "The Difference of Relative Elements is:" << endl;
        cout << endl;

        for ( int i=0 ; i < size ; i++ )
        {
            cout << "Difference of Element #" << i+1 << " of Vectors: ";

            if (A[i] > B[i])
            {
                cout << A[i] - B[i];
            }
            else
            {
                cout << B[i] - A[i];
            }

            cout << endl;
        }
        cout << endl;
        system("pause");


    // Generating Product

        system("cls");
        cout << endl;
        cout << "The Product of Relative Elements is:" << endl;
        cout << endl;

        for ( int i=0 ; i < size ; i++ )
        {
            cout << "Product of Element #" << i+1 << " of Vectors: " << A[i] * B[i] << endl;
        }
        cout << endl;
        system("pause");

    // To make it Recursive

        main();
}
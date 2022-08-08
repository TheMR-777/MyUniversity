#include <iostream>
#include <array>
using namespace std;



int calc(array<int, 5> &A , bool op)
{
    int sum=0;
    for ( int i=0 ; i<A.size() ; i++)
    {
        sum += A[i];
    }

    if (op == 0)
    {
        return sum;
    }
    else
    {
        return sum/A.size();
    }
    
}



void STL_input(array<int, 5> &A)
{
    for ( int i=0 ; i < A.size() ; i++)
    {
        cout << " Enter Element #" << i+1 << " : ";
        cin >> A[i];
    }
    cout << endl;
}



void STL_output(array<int, 5> &A)
{
    cout << "The SUM is : \t\t" << calc(A , 0) << endl;
    cout << "The Average is : \t" << calc(A , 1) << endl;
    cout << endl;
}




int main()
{
    // Initialization

        array<int, 5> A;

    // Introduction

        system("cls");
        cout << endl;
        cout << " Enter Elements of the STLA as asked" << endl;
        cout << endl;

    // Input 

        STL_input(A);

    // Output

        STL_output(A);

    // Recursive

        system("pause");
        main();
}
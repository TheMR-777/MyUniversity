#include <iostream> 
using namespace std;

int main()
{
    // Initialization

        int *Test_Array = new int[10];
        int test = 20;

    // Input

        for ( int i=0 ; i < 10 ; i++ )
        {
            Test_Array[i] = i;
            cout << Test_Array[i] << endl; 
        }

    // Deletion

        delete[] Test_Array;
}
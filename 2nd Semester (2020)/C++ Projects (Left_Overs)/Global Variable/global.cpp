#include <iostream> 
#include <vector>
using namespace std;

// Global Variable
    int number;


void access()
{
    number = 5;
    cout << number << endl;
}

int main()
{
    // Accessing Global Variable via MAIN

        number = 10;
        cout << number << endl;

    // Accessing Global Variable via FUNCTION

        access();
}
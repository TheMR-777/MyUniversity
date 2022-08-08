#include <iostream> 
using namespace std;

int main()
{
    // Initialization
    
        int *test = new int(10);

    // Output Check

        cout << *test << endl;

    // Riverting Changes in Memory

        delete test;
}
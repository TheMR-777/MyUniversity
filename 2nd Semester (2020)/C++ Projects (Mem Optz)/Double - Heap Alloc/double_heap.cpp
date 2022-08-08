#include <iostream> 
using namespace std;

int main()
{
    // Initialization

        double* d_test = new double(10);
        cout << *d_test << endl;

        *d_test = 30;
        cout << *d_test << endl;
}
#include <iostream>
using namespace std;


int fact(int n)
{
    return n * fact( n - 1 );
}

int main()
{
    // Initialization

        int n;

    // Getting input 

        cout << " Enter the Number : ";
        cin >> n;

    // Output

        cout << " Factorial : " << fact(n) << endl;
}
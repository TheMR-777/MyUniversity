#include <iostream>
using namespace std;

int main()
{
    // This is rvalue reference :

        int&& rval_r = 107;

    // Checking the results

        cout << rval_r << endl;
}
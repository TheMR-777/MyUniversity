#include <iostream>
#include <cmath>
#define Log(x) cout << x << endl
using namespace std;

int main()
{
    // Initialization

        int i;
        double d;
        float f;

    // Using integer

        Log("");
        i = -10;
        Log(abs(i));


    // Using float

        Log("");
        f = -7.77;
        Log(fabsf(f));


    // Using double

        Log("");
        d = -8.9989;
        Log(fabs(d));
}
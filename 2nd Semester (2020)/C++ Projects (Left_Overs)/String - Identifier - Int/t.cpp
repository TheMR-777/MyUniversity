#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string stg;
    int n;

    stg = "1001";

    for ( char c : stg )
    {
        n = (int)stg[c];
        cout << n << endl;
    }
}

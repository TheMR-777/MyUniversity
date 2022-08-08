#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string stg, prop;
    stringstream sss;
    int I;

    stg = "I have got 10 in math, and 15 in phy";

    for ( char c : stg )
    {
        if ( c >= '0' && c <= '9' )
        {
            sss << c;
            sss >> I;
            cout << I;
            sss = stringstream();
        }
        else
        {
            
        }
    }
}
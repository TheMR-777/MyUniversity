#include <iostream>
using namespace std;

int main()
{
    cout << " +----------------------------------+" << endl;
    
    for ( int i=0 ; i <= 256 ; i++ )
    {
        cout << " | [" << i << "] - " << (char)i << endl;
    }
}
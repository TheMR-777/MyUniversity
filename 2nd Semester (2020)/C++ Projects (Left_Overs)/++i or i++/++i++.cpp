#include <iostream>
using namespace std;

int main()
{
    int arr[5], i=0;

    while ( i < 5 )
    {
        arr[i] = i++;
    }

    for ( i = 0; i < 5; i++ )
    {
        cout << i << endl;
    }
}
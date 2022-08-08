#include <iostream>
using namespace std;


unsigned long long int s_fact(unsigned short int &n)
{
    unsigned long long int result = 1;
    for ( int i=n ; i > 0 ; i = i - 2 )
    {
        result *= i;
    }
    return result;
}


int main()
{
    // Intialization

        unsigned short int n;
    
    // Main Menu

        system("cls");
        M:
        cout << endl;
        cout << " +----------------------------------------+" << endl;
        cout << " |   It's a Double Factorial Calculator   |" << endl;
        cout << " |   Enter any number in the given range  |" << endl;
        cout << " |   to calculate its Double Factorial    |" << endl;
        cout << " |          ( Range : 1 - 65 )            |" << endl;
        cout << " +----------------------------------------+" << endl;
        cout << " |" << endl;
        cout << " +--[Input]--> ";
        cin >> n;
        cout << " |" << endl;
        cout << " +----------------------------------------+" << endl;
        cout << " | - Double Factorial : [ " << s_fact(n) << " ]" << endl;
        cout << " +----------------------------------------+" << endl;
        goto M;
}
#include <iostream> 
#include <fstream>
#include <array>
using namespace std;

int main()
{
    // Initialization

        int sum=0;
        array<int, 5> A;
        ofstream FILE ("SUM.txt");

    // Input

        cout << endl;
        cout << "It's a Program, which will show u the sum of 5 Quantities in an External File" << endl;
        cout << "named " << endl;
        cout << "Enter Elements of the Vector Below, as asked" << endl;
        cout << endl;

        for ( int i = 0 ; i < A.size() ; i++ )
        {
            cout << "Enter Element #" << i+1 << " : ";
            cin >> A[i];
            sum = sum + A[i];
        }

    // Output in File

        FILE << sum;
}
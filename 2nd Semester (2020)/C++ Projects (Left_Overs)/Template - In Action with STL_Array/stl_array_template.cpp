#include <iostream>
#include <array>
using namespace std;

// Only works in Visual Studio

template<typename Ty, unsigned int any>
void PrintSTLA(array<Ty, any> &S_A)
{
    for ( int i=0; i < S_A.size(); i++ )
    {
        cout << "Element #" << i+1 << " - [ " << S_A[i] << " ]" << endl;
    }
}

int main()
{
    array<int , 5> A = { 34 , 65 , 23 , 11 , 43 };
    PrintSTLA(A);
}
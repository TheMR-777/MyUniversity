#include <iostream>
using namespace std;

template<typename T>
void Print ( T val )
{
    cout << val << endl;
}

int main()
{
    Print ("The_Overloaded_Function");
    Print (10);
    Print (1.2f);
    Print (2456.124553234);
}
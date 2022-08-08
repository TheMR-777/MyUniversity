#include <iostream> 
#include <vector>
using namespace std;

int Smaller(const int& a, const int& b)
{
    if ( a < b ) return a;
    else return b;
}

int main()
{
    int a, b;
    cout << " Enter 1st Integer  : ";
    cin >> a;
    cout << " Enter 2nd Integer  : ";
    cin >> b;

    cout << " The Smaller One is : " << Smaller(a,b) << endl;
}
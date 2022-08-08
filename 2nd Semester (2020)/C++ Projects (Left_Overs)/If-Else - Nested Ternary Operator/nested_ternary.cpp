#include <iostream> 
using namespace std;

int main()
{
    int a , b;

    cout << endl;
    cout << "--------------------------------" << endl;
    cout << " Enter 1st Value : ";
    cin >> a;
    cout << " Enter 2nd Value : ";
    cin >> b;
    cout << "--------------------------------" << endl;

    ( a == b) ? cout << "Both are equal" << endl :
    ( a > b ) ? cout << "A is Bigger than B" << endl :
    ( b < a ) ? cout << "B is bigger than A" << endl :
                cout << "Error Occured!" << endl;
}
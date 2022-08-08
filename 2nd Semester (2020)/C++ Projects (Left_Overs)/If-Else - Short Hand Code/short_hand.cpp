#include <iostream> 
using namespace std;

int main()
{
    double t;
    cout << "Enter the Number : ";
    cin >> t;

    string msg = (t < 50) ? "Good" : "Not Good";

    cout << msg;
}
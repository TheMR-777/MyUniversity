#include <iostream>
using namespace std;

int main()
{
    int n, r = 0,s;

    cout << "Enter an integer from -99 to 99 ";
    cin >> n;
    s = n%10;
    r = r*10 + s;
    n /= 10;
    
    cout<< "the first digit is = " << n << endl;
    cout << "last digit is = " << r << endl;
   

    return 0;
}

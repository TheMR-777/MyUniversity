#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
    double a,b,c;
    cout << "- Select the Number, according to your choice: \n- 1, For Addition \n- 2, For Subtraction \n- 3, For Division \n- 4, For Multiplication" << endl;
    cin >> c;
    if (c == 1)
    {
        cout << "\n- Enter 1st Number: ";
        cin >> a;
        cout << "\n- Enter 2nd Number: ";
        cin >> b;
        cout << "\n- SUM: " << (a+b) << endl;
    }
    else if (c == 2)
    {
        cout << "\n- Enter 1st Number: ";
        cin >> a;
        cout << "\n- Enter 2nd Number: ";
        cin >> b;
        cout << "\n- Subtracted: " << (a-b) << endl;
    }
    
    else if (c == 3)
    {
        cout << "\n- Enter 1st Number: ";
        cin >> a;
        cout << "\n- Enter 2nd Number: ";
        cin >> b;
        cout << "\n- Division: " << (a/b) << endl;
    }
    else if (c == 4)
    {
        cout << "\n- Enter 1st Number: ";
        cin >> a;
        cout << "\n- Enter 2nd Number: ";
        cin >> b;
        cout << "\n- Product: " << (a*b) << endl;
    }
    else
    cout << "Invalid Number Entered" << endl;
    
    
    
}

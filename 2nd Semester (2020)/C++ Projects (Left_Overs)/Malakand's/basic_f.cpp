#include <iostream> 
#include <vector>
#include <cmath>
using namespace std;

int sum(int A , int B)
{
    return (A+B);
}

int pro(int A , int B)
{
    return (A*B);
}

void calc()
{
    // Initialization

        int A , B;
        int choice;
    
    // Main Code:

        cout << endl;
        cout << "Enter two Values as asked ..." << endl;
        cout << "Enter value #1 : ";
        cin >> A;
        cout << "Enter value #2 : ";
        cin >> B;
        cout << endl;

        cout << "Select Operation Below :" << endl;
        cout << "1. Sumation" << endl;
        cout << "2. Product" << endl;
        cout << "3. Power" << endl;
        cout << " > ";
        cin >> choice;

    // Decision Making

        switch(choice)
        {
            case 1:
            {
                cout << "The SUM of Entered values is : " << sum(A,B) << endl;
                break;
            }
            case 2:
            {
                cout << "The Product of Entered values is : " << pro(A,B) << endl;
                break;
            }
            case 3:
            {
                cout << "The A to the Power of B : " << pow(A,B) << endl;
                break;
            }
            default:
            {
                cout << "Invalid Choice" << endl;
                break;
            }
        }
}

int main()
{
    // Redirection

        calc();

    // Resursion

        main();
}
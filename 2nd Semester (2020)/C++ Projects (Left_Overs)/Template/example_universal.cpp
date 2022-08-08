#include <iostream>
#include <vector>
using namespace std;

template<typename T>

T SUM( T X , T Y )
{
    return (X+Y);
}



void T_string()
{
    string sX, sY;

    sX = "Wow ";
    sY = "Amazing!";

    cout << SUM(sX , sY);
}

void T_int()
{
    int iX, iY;

    iX = 5;
    iY = 10;

    cout << SUM(iX , iY);
}

void T_double()
{
    double dX, dY;

    dX = 5.0;
    dY = 10.0;

    cout << SUM(dX , dY);
}

void T_char()
{
    char cX, cY;

    cX = 'A';
    cY = 'B';

    cout << SUM(cX , cY);
}


int main()
{
    int choice;
    
    cout << "Enter input from below, to test the VOID Codes." << endl;
    cout << endl;
    cout << " 1. String Combination" << endl;
    cout << " 2. SUM of Integers" << endl;
    cout << " 3. SUM of doubles" << endl;
    cout << " 4. Characters Combination" << endl;
    cout << endl;
    cout << "Your Choice : ";
    cin >> choice;

    cout << endl;
    switch (choice)
    {
        case 1:
        {
            T_string();
            break;
        }

        case 2:
        {
            T_int();
            break;
        }
        case 3:
        {
            T_double();
            break;
        }
        case 4:
        {
            T_char();
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}
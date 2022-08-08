#include <iostream>
using namespace std;



template<typename T>
void F_Swap(T &x, T &y)

{
    T z;
    z = x;
    x = y;
    y = z;
    cout << "\nHere is the result \n";
    cout << x << endl << y;
}



template<typename T>
void input(T &A)
{
    switch (A)
    {
        case 'i':
        {
            int x, y;
            cout << "Please enter the integer values to be swaped as asked" << endl;
            cout << endl;
            cout << "1st Integer : ";
            cin >> x;
            cout << "1st value entered successfully, plz enter the 2nd value : ";
            cin >> y;
            F_Swap(x, y);
            break;
        }
        
        case 'c':
        {
             char x,y;
             cout << "Please enter the characters you want to swap, as asked" << endl;
             cout << endl;
             cout << "1st Character : ";
             cin >> x;
             cout<<"1st char entered now enter 2nd char : ";
             cin>>y;
             F_Swap(x, y);
             break;

        }
        case 's':
        {
             string x,y;
             cout<<"Please enter the strings you want to swap" << endl;
             cout << endl;
             cout << "1st String : ";
             cin>>x;
             cout<<"1st string entered now enter 2nd string : ";
             cin>>y;
             F_Swap(x, y);
             break;
        }
    }


}





int main()
{
    char A;

    cout << "Please make a decision" << endl;
    
    cout << endl;
    cout << "[ i ] - For Integer Swapping." << endl;
    cout << "[ c ] - For CHaracter Swapping." << endl;
    cout << "[ s ] - For String Swapping." << endl;
    cout << endl;

    cout << "- Enter desired character : ";
    cin >> A;
    input(A);
}

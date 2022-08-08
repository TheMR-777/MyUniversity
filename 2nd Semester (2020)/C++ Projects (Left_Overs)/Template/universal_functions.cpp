#include <iostream>
#include <vector>
using namespace std;
template<typename ANY>


void INPUT ( ANY &X , ANY &Y )
{
    cout << endl;
    cout << "Enter 1st Input : ";
    cin >> X;
    cout << "Enter 2nd Input : ";
    cin >> Y;
}

namespace OUTPUT
{
    template<typename ANY>

    ANY SUM( ANY X , ANY Y )
    {
        return ( X + Y );
    }


}


void decision( bool &c )
{
    switch (c)
    {
        case 0:
        {
            int iX , iY;
            INPUT( iX , iY );
            cout << "The OUTPUT : " << OUTPUT::SUM( iX , iY );
            break;
        }

        case 1:
        {
            string sX , sY;
            INPUT( sX , sY );
            cout << "The OUTPUT : " << OUTPUT::SUM( sX , sY );
            break;
        }
    }

}


void program()
{
    // Initialization

        bool choice;    

    // Main Menu

        cout << endl;
        cout << " +-------------------------------------------------------------------------+" << endl;
        cout << " | It's an Example Program to show you the working of Templates. Here, I   |" << endl;
        cout << " | have also used the concept of namespace, to show, how we have to create |" << endl;
        cout << " | another template, when we create a namespace. In my case, I've made     |" << endl;
        cout << " | both Templates with the same name, to avoid complication.               |" << endl;
        cout << " +-------------------------------------------------------------------------+" << endl;
        cout << " | Choose from below, to check the working mechanism of Templates          |" << endl;
        cout << " +-------------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << " Choose any one Option" << endl;
        cout << endl;
        cout << " 0. Taking SUM of Integers" << endl;
        cout << " 1. Combining two Strings" << endl;
        cout << endl;
        cout << "Make a Decision : ";
        cin >> choice;

    // Decision

        decision(choice);
}


int main()
{
    system("cls");
    program();
    cout << endl;
    system("pause");
    main();
}

#include <iostream>
#include <vector>
using namespace std;

template<typename TT>


void swap( TT &A , TT &B )
{
    TT temp;
    temp = A;
    A = B;
    B = temp;
} 

void INPUT(bool &choice)
{
    // Logic Design
    
    switch(choice)
    {
        case 0:
        {
            int iX , iY;
            cout << "Enter 1st Integer : ";
            cin >> iX;
            cout << "Enter 2nd Integer : ";
            cin >> iY;

            swap(iX , iY);
            cout << endl;

            cout << "1st Integer is now : " << iX << endl;
            cout << "2nd Integer is now : " << iY << endl;
        }

        case 1:
        {
            string sX , sY;
            cout << "Enter 1st String : ";
            cin >> sX;
            cout << "Enter 2nd String : ";
            cin >> sY;

            swap(sX , sY);
            cout << endl;

            cout << "1st String is now : " << sX << endl;
            cout << "2nd String is now : " << sY << endl;
        }
    }
}



int main()
{
    
    // Initialization

        bool choice;

    // Main Menu

        system("cls");
        cout << endl;
        cout << "Enter any one Operation below" << endl;
        cout << endl;
        cout << "0. Swapping Integers" << endl;
        cout << "1. Swapping Strings" << endl;
        cout << endl;
        cout << "- Your Choice : ";
        cin >> choice;

    // Now, function will handle everuthing

        INPUT(choice);
        
    // Recursive

        main();
}

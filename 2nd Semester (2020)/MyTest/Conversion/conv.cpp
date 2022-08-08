#include <iostream>
using namespace std;

int main()
{
    // Initialization

        int n;


    // Input

        system("cls");
        cout << "It's a BASE_Conversion Program" << endl;
        cout << endl;

        cout << "Enter any Decimal Number: ";
        cin >> n;


    // Results

        system("cls");
        cout << endl;
        cout << " +---------------------------------------------------------+" << endl;
        cout << " | Decimal: " << dec << n << "\t\tOcta :" << oct << n << "\tHex : " << hex << n << endl;
        cout << " +---------------------------------------------------------+" << endl;
        cout << endl;

        system("pause");


    // Recursivs

        main();

}
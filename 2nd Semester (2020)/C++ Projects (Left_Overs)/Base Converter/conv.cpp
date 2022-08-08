#include <iostream>
#include <cmath>
using namespace std;


int octalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}


int main()
{
	// TO Avoid Confliction
    
        system("cls");


    // Initialization + Input

        int n=0;
        cout << "\n- Enter Number: ";
        cin >> n;
        

    // Results
	
        system("cls");
        cout << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << " Decimal: " << dec << n << "\t|\tHex: " << hex << n << "\t|\tOcta   : " << oct << n << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << " Octal  : " << dec << n << "\t|\tHex: " << hex << octalToDecimal(n) << "\t|\tDecimal: " << dec << octalToDecimal(n) << endl;
        cout << "-------------------------------------------------------------" << endl;
	

	// Finalizing

	    system("pause");
	    main();
}

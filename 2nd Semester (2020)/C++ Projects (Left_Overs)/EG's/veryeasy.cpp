#include <iostream> 
using namespace std;

int main()
{
    // Initialization

        string stg;

    // Input

        system("cls");
        cout << "Enter any String Below : " << endl;
        cout << " > ";
        getline(cin , stg);

    // Output

        cout << endl;
        cout << "1st  Letter >  " << stg[0] << endl;
        cout << "Last Letter >  " << stg[ stg.length() - 1 ] << endl;

    // Finalization

        cout << endl;
        system("pause");
        main();
}
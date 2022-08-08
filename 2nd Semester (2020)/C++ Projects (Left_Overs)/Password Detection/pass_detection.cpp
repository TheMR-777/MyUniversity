#include <iostream>
using namespace std;

void guess()
{
    // Initialization

        int pass;
        int u_pass;

    // Hard-Coding Password

        pass = 1001;

    // Getting user Input

        cout << endl;
        cout << "Enter the Password : ";
        cin >> u_pass;

    // Loops for Correct Password

        loop:
        if ( u_pass != pass )
        {
            while ( u_pass != pass)
            {
                cout << "Sorry, your Entered Password is Incorrect" << endl;
                cout << endl;
                cout << "Enter right Password : ";
                cin >> u_pass;
                goto loop;
            }
        }
        else
        {
            cout << "Yes, U Entered Right Password" << endl;
        }
        cout << endl;
        system("pause");
        
}





int main()
{
	string choice;
	
	
	// Presented By
	
	
	cout << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |                        Presented By                         |" << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |                                                             |" << endl;
	cout << " |  `7MMM.     ,MMF'`7MM*^*Mq.                                 |" << endl;
	cout << " |    MMMb    dPMM    MM   `MM.                                |" << endl;
	cout << " |    M YM   ,M MM    MM   ,M9    M******A'M******A'M******A'  |" << endl;
	cout << " |    M  Mb  M' MM    MMmmdM9     Y     A' Y     A' Y     A'   |" << endl;
	cout << " |    M  YM.P'  MM    MM  YM.          A'       A'       A'    |" << endl;
 	cout << " |    M  `YM'   MM    MM   `Mb.       A'       A'       A'     |" << endl;
	cout << " |  .JML. `'  .JMML..JMML. .JMM.     A'       A'       A'      |" << endl;
	cout << " |                                  A'       A'       A'       |" << endl;
 	cout << " |                         mmmmmmm A'       A'       A'        |" << endl;
 	cout << " |                                                             |" << endl;
 	cout << " +-------------------------------------------------------------+" << endl;
 	cout << "\n\n\n" << endl;
 	system("timeout 5");
	
	
	// Main Menu
	
	
	do
	{
		system("cls");
		cout << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "|              There's a Password Hard-Coded in the Program           |" << endl;
		cout << "|          Only you have to do is to guess the Right Password         |" << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "| - Enter 0 to Quit                                                   |" << endl;
		cout << "| - Enter Any other key to \"Guess the Password\"                        |" << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "\n- Your Choice: ";
		getline(cin, choice);
		
		if (choice != "0")
		{
			guess();
		}
		else
		{
			return 0;
		}
	}
	while (choice != "0");
}

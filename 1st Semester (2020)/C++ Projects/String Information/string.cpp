#include <iostream>
using namespace std;

int main()
{
	// Intro + Initialization
	
		string stg;
		cout << "\n- Enter any String: ";
		getline (cin, stg);
		system("cls");

	// Generating Results
		
		cout << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "String Entered: \t" << stg << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "String Size:\t\t" << stg.size() << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "String in Reverse: \t";
	
	//Reverse Loop for Reverse String

		for(int i = (stg.size()-1) ; i>=0 ; i--)
		{
			cout << stg[i];
		}
		cout << endl;
		
		cout << "--------------------------------------------------" << endl;
	
		cout << "\n\n" << endl;
		system("pause");
}

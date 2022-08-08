#include <iostream>
using namespace std;



void table(int &nbr, int &lmt)
{
	for (int i=01 ; i<=lmt ; i++)
	{
		cout << "  " << nbr << " x " << i << " = " << nbr*i << endl;
	}
}




int main()
{
	int nbr, lmt;
	do
	{
		system("cls");
		cout << endl;
		cout << " +--------------------------------------------------------+" << endl;
		cout << " | In the following field, enter the number whose Table   |" << endl;
		cout << " | you wanna generate.                                    |" << endl;
		cout << " | ------------------------------------------------------ |" << endl;
		cout << " | - Enter the Number: ";
		cin >> nbr;
		cout << " +--------------------------------------------------------|" << endl;
		cout << " | In following field, enter the limit where table ends   |" << endl;
		cout << " | ------------------------------------------------------ |" << endl;
		cout << " | - Enter Limit: ";
		cin >> lmt;
		
		system("cls");
		cout << " +--------------------------------------------------------+" << endl;
		table(nbr, lmt);
		cout << " +--------------------------------------------------------+" << endl;
		cout << "\n\n\n" << endl;
		system("pause");
	}
	while(true);
}

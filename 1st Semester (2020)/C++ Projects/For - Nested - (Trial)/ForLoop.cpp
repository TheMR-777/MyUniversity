#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	int z;
	x:
	cout << "Enter any Number: ";
	cin >> z;
	cout << endl;
	for (int x=1 ; x<=z ; x++)
	{
		for (int y=1 ; y<=x ; y++)
		{
			cout << "7";
		}
		cout << endl;
	}
	goto x;
	return 0;
}

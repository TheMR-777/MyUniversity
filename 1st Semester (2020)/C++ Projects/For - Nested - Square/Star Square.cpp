#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int i;
	StarSquare:
	cout << "\nEnter Limit (Recommended: 1-55): ";
	cin >> i;
	cout << "\n";
	for (int x=0 ; x<=i ; x++)
	{
		for (int y=0; y<=i; y++)
		{
			cout << " O";          // Use { cout << y << " "; } for a different Result!
		}
		cout << endl;
	}
	goto StarSquare;
	return 0;
}
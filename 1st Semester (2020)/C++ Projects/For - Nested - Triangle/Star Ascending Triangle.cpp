#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int i;
	StarTriangle:
	cout << "Enter Limit: ";
	cin >> i;
	for (int x=0 ; x<=i ; x++)
	{
		for (int y=0; y<x; y++)
		{
			cout << y << " ";          // Use { cout << y << " "; } for a different Result!
		}
		cout << endl;
	}
	goto StarTriangle;
	return 0;
}

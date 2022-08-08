#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int i;
	StarLimited:
	cout << "Enter Limit: ";
	cin >> i;
	for (int x=0 ; x<i; x++)
	{
		for (int y=0; y<9; y++)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	goto StarLimited;
	return 0;
}

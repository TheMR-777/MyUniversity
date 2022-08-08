#include <iostream>
using namespace std;

int main()
{
	int sum=0;
	int X[5];
	cout << "\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter Number: (" << i + 1 << ") = ";
		cin >> X[i];
		sum = sum + X[i];
	}
	cout << "\nShowing Sum of all Numbers, SUM = [ " << sum << " ]";
	cout << "\n"; 
	system("pause");
}


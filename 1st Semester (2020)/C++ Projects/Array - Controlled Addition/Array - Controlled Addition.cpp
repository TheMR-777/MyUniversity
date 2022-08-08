#include <iostream>
using namespace std;

int main()
{
	int s; double sum=0;
	cout << "\n- Enter Integers to be Entered: ";
	cin >> s;
	int X[s];
	cout << "\n";
	for (int i = 0; i < s; i++)
	{
		cout << "Enter Number: (" << i + 1 << ") = ";
		cin >> X[i];
		sum = sum + X[i];
	}
	cout << "\nShowing Sum of All, SUM = [ " << sum << " ]";
	cout << "\n"; 
	system("pause");
}


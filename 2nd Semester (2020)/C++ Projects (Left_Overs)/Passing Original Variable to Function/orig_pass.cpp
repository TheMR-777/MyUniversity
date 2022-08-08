#include <iostream>
using namespace std;


void power_x(int &n)
{
	n=n*n;
}


int main()
{
	do
	{
		int n;
		cout << " +------------------------------------------------------+" << endl;
		cout << " | - Enter Number to Multiply with its own : ";
		cin >> n;
		
		power_x(n);
		cout << " | ---------------------------------------------------- |" << endl;
		cout << " |  Output : " << "\t" << n << endl; 
	}
	while(true);
}

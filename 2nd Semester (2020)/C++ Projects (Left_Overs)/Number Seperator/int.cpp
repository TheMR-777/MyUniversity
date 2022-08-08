#include<iostream>
using namespace std;


void separator(int n)
{
	while (n != 0)
	{
		cout << n % 10 << endl;
		n /= 10;
	}
}

int main()
{
	int i = 167;
	separator(i);
}
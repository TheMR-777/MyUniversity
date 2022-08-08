#include <iostream>
using namespace std;

int status(int m)
{
	if (m < 33)
	{
		cout << "Please Enter Your Passing Marks: ";
		cin >> m;
		status(m);
	}
	else
	{
		return m;
	}
}



int main()
{
	x:
	int m;
	cout << "Enter your Marks: ";
	cin >> m;
	if (status(m) >= 33)
	{
		cout << "YES, U R passed!" << endl;
		goto x;
	}
	else
	{
		cout << "Sorry, something went wrong ..." << endl;
	}
}

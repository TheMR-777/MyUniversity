#include <iostream>
#include <thread>
using namespace std;


string dots(int &x)
{
	string s;
	for (int i = 0; i < x; i++)
	{
		s += "-";
	}

	for (int i = 0; i < (100 - x); i++)
	{
		s += " ";
	}
	return s;
}

int main()
{
	for (int i = 0; i <= 100; i++)
	{
		cout << "[ " << dots(i) << " ]" << " - " << i << "%\r";
		std::this_thread::sleep_for(0.05s);
	}
	cout << endl;
}
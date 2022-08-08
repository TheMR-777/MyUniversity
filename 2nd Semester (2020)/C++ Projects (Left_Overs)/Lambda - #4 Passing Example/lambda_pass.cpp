#include <iostream>
#include <vector>
using namespace std;

void jumper(vector<int> V, void(*func)(int))
{
	for (int &ptr : V)
	{
		func(ptr);
	}
}

int main()
{
	// Initialization

		system("cls");
		vector<int> values = { 4, 5, 6, 1, 6, 3, 7, 34 };

	// Calling Function and passing Lambda

		jumper(values, [](int dis) { cout << "Integer Value : " << dis << endl; });
}
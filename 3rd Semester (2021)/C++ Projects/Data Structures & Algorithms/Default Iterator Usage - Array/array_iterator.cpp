#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<int, 10> A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Range Based For Loop" << endl;
	for (auto& val : A)
	{
		cout << val << endl;
	}

	cout << "Standard For Loop, using Iterator" << endl;
	for (auto it = A.begin(); it != A.end(); ++it)
	{
		cout << *it << endl;
	}
}
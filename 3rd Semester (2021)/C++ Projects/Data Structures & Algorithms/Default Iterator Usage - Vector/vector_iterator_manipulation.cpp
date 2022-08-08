#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Replacing all Evens with their Next Odds" << endl;

	for (auto it = A.begin(); it != A.end(); ++it)
	{
		if ((*it) % 2 != 0)
		{
			*it = *it + 1;
		}
	}

	for (auto& it : A)
	{
		cout << it << endl;
	}
}
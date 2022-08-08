#include <iostream>
using namespace std;

template<typename T>
T round_custom(T f, int n = 2)
{
	int round = 1;
	for (int i = 0; i < n; i++)
	{
		round *= 10;
	}
	return ((float)(int)((f * round) + 0.5)) / round;
}


int main()
{
	// Initialization

		float n, r;


	// Input

		cout << "Insert the number to be rounded off : ";
		cin >> n; cin.clear(); cin.sync();

		cout << "What should be the maximum decimal significant figures : ";
		cin >> r; cin.clear(); cin.sync();


	// Result

		cout << endl;
		cout << "The Rounded off Number : " << round_custom(n, r);
}

#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename F>
void jumper(vector<T> V, F func)
{
	for (T &ptr : V)
	{
		func(ptr);
	}
}

int main()
{
	// Initialization

	system("cls");
	vector<int> values = { 4, 5, 6, 1, 6, 3, 7, 34 };
	vector<string> strings = { "Random #1" , "Random #2" , "Random #3" , "Random #4" , "Random #5" , "Random #6" };

	// Calling the same Function with Modified Lambda

	jumper(values, [](int dis) { cout << dis << endl; });
	jumper(values, [](std::string disp) { cout << disp << endl; });
}
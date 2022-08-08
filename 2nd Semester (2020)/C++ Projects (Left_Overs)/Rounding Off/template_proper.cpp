#include <iostream>
#define Log(x) cout << x << endl
using namespace std;

template<typename T>
T round_custom(T f, int n)
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
	Log(round_custom(56.2365755, 2));
}

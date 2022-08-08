#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


float round_custom(float f)
{
	return ((float)(int)(f * 100)) / 100;
}


int main()
{
	Log(round_custom(56.2365755));
}

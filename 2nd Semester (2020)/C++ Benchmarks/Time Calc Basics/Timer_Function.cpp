#include <iostream> 
#include <chrono>
using namespace std;

struct Timer
{
	chrono::time_point<chrono::steady_clock> start, end;

	Timer()
	{
		start = chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = chrono::high_resolution_clock::now();
		cout << (end - start).count() / 1000000 << "ms" << endl;
	}
};




void test()
{
	Timer T;
	
	for (int i = 0; i < 100; i++)
	{
		cout << "Testing ..." << endl;
	}
}

int main()
{
	Timer T1;
	test();
}
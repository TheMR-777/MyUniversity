#include <iostream> 
#include <chrono>
using namespace std;

void test()
{
	for ( int i=0 ; i < 200 ; i++ )
		cout << "Testing ..." << endl;
}

int main()
{
	// Getting current time

	    auto start = chrono::high_resolution_clock::now();

	// Doing something

	    test();

	// Getting current time

	    auto end = chrono::high_resolution_clock::now();

	// Time calculation

	    chrono::duration<float> dur = end - start;

	// Showing the Time in milliseconds

	    cout << dur.count() * 1000 << "ms" << endl;
}
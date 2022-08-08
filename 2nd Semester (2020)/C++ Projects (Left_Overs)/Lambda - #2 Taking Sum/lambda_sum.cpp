#include <iostream>
using namespace std;

int main()
{
	// Initializing Lambda for SUM

        auto Lambda_Sum = [](int a, int b) -> int
        {
            return a + b;
        };

	// Calling Lambda

	    cout << Lambda_Sum(10, 70);
}
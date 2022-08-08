#include <iostream>						// U know ...
#include <cstdlib>						// Including C Libraries
#include <ctime>						// Including Libraries to Extract System' Time
using namespace std;

int main()
{
	
	srand(time(NULL));					// Using Your System Time to Generate Random Number
	
	int random = rand() % 101;			// Number after Modulus (%) sets the Maximum Range of Random Number
	
	cout << random << endl;				// Output
}

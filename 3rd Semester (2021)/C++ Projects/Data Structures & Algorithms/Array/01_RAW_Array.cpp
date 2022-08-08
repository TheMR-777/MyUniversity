#include<iostream>
using namespace std;

int main()
{
	// Initialization
	// --------------

		int stack_array[5];


	// Filling
	// -------

		for (int i = 0; i < 5; i++)
		{
			stack_array[i] = (i + 1) * 100;
		}


	// Output
	// ------

		for (int i = 0; i < 5; i++)
		{
			cout << "Element #" << i + 1 << " is : " << stack_array[i] << endl;
		}
}
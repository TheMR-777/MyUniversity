#include<iostream>
using namespace std;

int main()
{
	// Initialization
	// --------------

		// Size is Dynamic, and can be set Dynamically
		int* heap_array = new int[5];


	// Filling
	// -------

		for (int i = 0; i < 5; i++)
		{
			heap_array[i] = (i + 1) * 100;
		}


	// Output
	// ------

		for (int i = 0; i < 5; i++)
		{
			cout << "Element #" << i + 1 << " is : " << heap_array[i] << endl;
		}


	// Deletion
	// --------

		delete[] heap_array;
}
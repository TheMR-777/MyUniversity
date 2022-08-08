#include <iostream>
#include <vector>
using namespace std;



void insertionSort(vector<int>& V)
{
	int key, j;
	for (int i = 1; i < V.size(); i++)
	{
		key = V[i];
		j = i - 1;

		while (j >= 0 && V[j] > key)
		{
			V[j + 1] = V[j];
			j = j - 1;
		}
		V[j + 1] = key;
	}
}




int main()
{
	// Initialization

		vector<int> V{ 45, 34, 22, 1, 7, 56, 3, 23, 73, 23, 9, 27, 91 };

	// Sorting

		insertionSort(V);

	// Printing

		for( int i = 0; i < V.size(); i++ )
		{
			cout << "Element #" << i + 1 << " :\t [ " << V[i] << " ]" << endl;
		}
}
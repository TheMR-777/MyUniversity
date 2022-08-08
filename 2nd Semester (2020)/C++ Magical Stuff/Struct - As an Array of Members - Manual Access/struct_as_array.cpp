#include <iostream>
using namespace std;

struct Vector
{
	int x, y, z;
};

int main()
{
	// Initialization

	Vector V = { 5 , 10 , 100 };

	// Outputting the Results

	for (int i = 0; i < (sizeof(V) / sizeof(int)); i++)
	{
		cout << "Element #" << i+1 << " - [ " << *(int*)((char*)&V + i * sizeof(int)) << " ]" << endl;
	}
}
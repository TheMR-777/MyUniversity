#include <iostream>
using namespace std;

struct Vector
{
	int x, y, z;
};

int main()
{
    // Initialization

	    Vector V = { 1 , 3 , 7 };
	    int* V_Array = (int*)&V;

    // Outputting the Results

        for ( int i=0 ; i < (sizeof(V) / sizeof(int)) ; i++ )
        {
            cout << "Element #" << i+1 << " - [ " << V_Array[i] << " ]" << endl;
        }
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Initialization

		int size;
	
	// Creating a Suitable Vector

		cout << "\n- Enter SIZE of the Vector: ";
		cin >> size;
	
		vector<int> V(size);

	// Taking Input
	
		int sum=0;
		for (int i=0 ; i < V.size() ; i++)
		{
			cout << "Enter Element #" << i+1 << " : ";
			cin >> V[i];
			sum = sum + V[i];
		}

	// Displaying Sum

		cout << endl;
		cout << "The SUM of all Quantities is: " << sum << endl;

}

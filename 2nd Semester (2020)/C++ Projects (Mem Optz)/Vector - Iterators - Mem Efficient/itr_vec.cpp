#include <iostream> 
#include <vector>
using namespace std;

int main()
{
	// Initialization

	vector<int> V = { 4 , 3 , 6 , 2 , 7 , 4 , 9 , 12 };

	// Printing using it's own Iterator

	vector<int>::iterator itr;

	for (itr = V.begin() ; itr < V.end() ; itr++)
	{
		cout << *itr << endl;
	}
}
#include <iostream>
#include <tuple>
using namespace std;



pair<string, int> GetMan()
{
	return { "MR_", 777 };
}

int main()
{
	// Initialization

		string name; int n;
	
	// Getting the Credentials

		tie(name, n) = GetMan();

	// Outputting

		cout << "My Name : " << name << n << endl;
}
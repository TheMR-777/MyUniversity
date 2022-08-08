#include <iostream>
#include <tuple>
using namespace std;



pair<string, int> GetMan()
{
	return { "MR_", 777 };
}

int main()
{
	// Getting the Credentials

	    // pair<string, int> P = GetMan();
		auto P = GetMan();

	// Outputting

	    cout << get<0>(P) << get<1>(P) << endl;

        cout << P.first << P.second << endl;
}
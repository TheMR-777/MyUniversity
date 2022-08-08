#include <iostream>
#include <string>
#include <tuple>
using namespace std;



tuple<string, int, int> GetMan()
{
	return { "MR_", 777, 19 };
}

int main()
{
	// Getting the Credentials

		// tuple<string, int, int> Tup = GetMan();
		auto Tup = GetMan();

	// Outputting

		cout << "My Name : " << get<0>(Tup) << get<1>(Tup) << endl;
		cout << "AGE     : " << get<2>(Tup) << endl;
}
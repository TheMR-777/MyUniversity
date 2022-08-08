#include <iostream>
#include <tuple>
using namespace std;



tuple<string, int, int> GetMan()
{
	return { "MR_", 777, 19 };
}

int main()
{
	// Getting the Credentials

		auto[name, n1, age] = GetMan();
		// auto[name, n1, age] ( GetMan() );
		// auto[name, n1, age] { GetMan() };

	// Outputting

		cout << "My Name : " << name << n1 << endl;
		cout << "AGE     : " << age << endl;
}
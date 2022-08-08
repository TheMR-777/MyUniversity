#include <iostream>
using namespace std;



struct Someone
{
	string name;
	int n1, n2;
};

Someone GetMan()
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
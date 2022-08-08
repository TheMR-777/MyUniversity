#include <iostream>
#include <string>
#include <tuple>
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

		// Someone ME = GetMan();
		auto ME = GetMan();

	// Outputting

		cout << "My Name : " << ME.name << ME.n1 << endl;
		cout << "AGE     : " << ME.n2 << endl;
}
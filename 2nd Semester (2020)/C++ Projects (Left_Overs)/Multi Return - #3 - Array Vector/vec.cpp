#include <iostream>
#include <vector>
using namespace std;



vector<string> GetMan()
{
	return { "MR_", "777", "19" };
}

int main()
{
	// Getting the Credentials

		// vector<string> ME = GetMan();
		auto ME = GetMan();

	// Outputting

		cout << "My Name : " << ME[0] << ME[1] << endl;
		cout << "AGE     : " << ME[2] << endl;
}
#include <iostream>
#include <string>
#include <variant>
using namespace std;



int main()
{
	// Initialization

		string name;
		variant<string, int> slogan;

	// Setting Values

		name = "MR_777";
		slogan = 137;

	// Outputting the Initial Result

		cout << "The Name  : " << name << endl;

	// Checking the Type of Value of Slogan

		if (auto val = get_if<string>(&slogan))
		{
			cout << "Slogan    : " << get<string>(slogan) << endl;
		}
		else
		{
			cout << "Slogan    : " << get<int>(slogan) << endl;
		}
		cout << "Slogan ID : " << slogan.index() << endl;

	// Modifying Slogan -> String

		slogan = "Connection is Power!";

	// Printing

		cout << "The Name  : " << name << endl;

	// Checking the Type of Value of Slogan

		if (auto val = get_if<string>(&slogan))
		{
			cout << "Slogan    : " << get<string>(slogan) << endl;
		}
		else
		{
			cout << "Slogan    : " << get<int>(slogan) << endl;
		}
		cout << "Slogan ID : " << slogan.index() << endl;
}
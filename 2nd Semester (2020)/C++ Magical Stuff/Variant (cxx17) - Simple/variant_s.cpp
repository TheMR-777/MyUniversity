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

	cout << "The Name  : " << name << endl;
	cout << "Slogan    : " << get<int>(slogan) << endl;
	cout << "Slogan ID : " << slogan.index() << endl;

	slogan = "Connection is Power!";

	cout << "The Name  : " << name << endl;
	cout << "Slogan    : " << get<string>(slogan) << endl;
	cout << "Slogan ID : " << slogan.index() << endl;
}
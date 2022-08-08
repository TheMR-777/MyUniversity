#include <iostream>
#define Log(x) cout << x << endl
using namespace std;

class Abstract
{
	string m_Name, m_Gender;

	protected:

		Abstract(string& n, string& g)
			: m_Name(n), m_Gender(g) {}

		void Get_info()
		{
			Log("Name   : " << m_Name);
			Log("Gender : " << m_Gender);
		}
};

class Derived : private Abstract
{
public:

	Derived(string&& n, string&& g)
		: Abstract(n, g) {}

	void Get_info()
	{
		Abstract::Get_info();
	}
};


int main()
{
	// Dealing with Derived Class
	// --------------------------

		Derived D ("Grey", "Female");
		D.Get_info();
}
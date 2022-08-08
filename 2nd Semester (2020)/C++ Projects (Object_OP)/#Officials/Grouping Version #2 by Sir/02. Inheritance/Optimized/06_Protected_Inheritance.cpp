#include <iostream>
#define Log(x) cout << x << endl
using namespace std;

class Base
{
	string m_Name, m_Gender;

protected:

	Base(string n, string g)
		: m_Name(n), m_Gender(g) {}

	void Get_info()
	{
		Log("Name   : " << m_Name);
		Log("Gender : " << m_Gender);
	}
};

class Derived_Base : protected Base
{
protected:

	Derived_Base(string n, string g)
		: Base( n, g ) {}

	void Get_info()
	{
		Base::Get_info();
	}

};

class Derived : private Derived_Base
{
public:

	Derived(string&& n, string&& g)
		: Derived_Base(n, g) {}

	void Get_info()
	{
		Derived_Base::Get_info();
	}
};


int main()
{
	// Dealing with Derived Class
	// --------------------------

		Derived D ("Grey", "Female");
		D.Get_info();
}
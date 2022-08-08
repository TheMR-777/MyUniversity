#include <iostream>
using namespace std;

class Base
{
public:

	Base()
	{
		cout << "| BASE Constructor" << endl;
	}

	virtual
	void GetName()
	{
		cout << "| I am the Base Class!" << endl;
	}

	virtual
	~Base()
	{
		cout << "| BASE Destructor" << endl;
	}
};

class Derived : public Base
{
public:

	Derived()
	{
		cout << "| Derived Constructor" << endl;
	}

	void GetName() override
	{
		cout << "| I am the Derived Class!" << endl;
	}

	~Derived() override
	{
		cout << "| Derived Destructor" << endl;
	}
};




int main()
{
	// Using Base

	cout << "+---------------------------------------------------+" << endl;
	Base* Base_Test = new Base();
	Base_Test->GetName();
	delete Base_Test;

	// Using Derived

	cout << "+---------------------------------------------------+" << endl;
	Derived* Derived_Test = new Derived();
	Derived_Test->GetName();
	delete Derived_Test;

	// Using Derived as BASE

	cout << "+---------------------------------------------------+" << endl;
	Base* Derived_BASED = new Derived();
	Derived_BASED->GetName();
	delete Derived_BASED;

	// Finalize

	cout << "+---------------------------------------------------+" << endl;
}
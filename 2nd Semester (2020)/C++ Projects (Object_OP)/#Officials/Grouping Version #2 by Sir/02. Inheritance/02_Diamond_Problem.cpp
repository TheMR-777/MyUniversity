#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


class Base1
{

public:

	Base1()
	{
		Log("Constructor - Base #1 Created");
	}

	void Get_Base1()
	{
		Log("Function called from Base #1");
	}

	~Base1()
	{
		Log("Destructor - Base #1 Destructed");
	}
};


class Derived1 : public Base1
{

public:

	Derived1()
	{
		Log("Constructor - Derived #1 Created");
	}

	void Get_Der1()
	{
		Log("Function called from Derived #1");
	}

	~Derived1()
	{
		Log("Destructor - Derived #1 Destructed");
	}
};

class Derived2 : public Base1
{

public:

	Derived2()
	{
		Log("Constructor - Derived #2 Created");
	}

	void Get_Der2()
	{
		Log("Function called from Derived #2");
	}

	~Derived2()
	{
		Log("Destructor - Derived #2 Destructed");
	}
};

class Derived3 : public Derived1, public Derived2
{

public:

	Derived3()
	{
		Log("Constructor - Derived #3 Created");
	}

	void Get_Der3()
	{
		Log("Function called from Derived #3");
	}

	~Derived3()
	{
		Log("Destructor - Derived #3 Destructed");
	}
};



int main()
{
	// 01. Dealing with Base Class #1
	// ===------------------------===

		Log("\n [ 1 ] \n");
		Base1 B1;
		B1.Get_Base1();


	// 02. Dealing with Derived Class #1
	// ===---------------------------===

		Log("\n [ 2 ] \n");
		Derived1 D1;
		D1.Get_Der1(); D1.Get_Base1();


	// 03. Dealing with Derived Class #2
	// ===---------------------------===

		Log("\n [ 3 ] \n");
		Derived2 D2;
		D2.Get_Der2(); D2.Get_Base1();


	// 04. Dealing with Derived Class #3
	// ===---------------------------===

		Log("\n [ 4 ] \n");
		Derived3 D3;
		D3.Get_Der3(); D3.Get_Der2(); D3.Get_Der1();


	// Finalize

		Log("\n [ 5 ] \n");

}
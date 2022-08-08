#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


class Base1
{

public:

	void Get_Base1()
	{
		Log("Function called from Base #1");
	}
};

class Base2
{

public:

	void Get_Base2()
	{
		Log("Function called from Base #2");
	}
};

class Derived1 : public Base1
{

public:

	void Get_Der1()
	{
		Log("Function called from Derived #1");
	}
};

class Derived2 : public Base2
{

public:

	void Get_Der2()
	{
		Log("Function called from Derived #2");
	}
};

class Derived3 : public Base1, public Base2
{

public:

	void Get_Der3()
	{
		Log("Function called from Derived #3");
	}
};

class Derived4 : public Derived3
{

public:

	void Get_Der4()
	{
		Log("Function called from Derived #4");
	}
};



int main()
{
	// 01. Dealing with Base Class #1
	// ===------------------------===

		Log("\n [ 1 ] \n");
		Base1 B1;
		B1.Get_Base1();


	// 02. Dealing with Base Class #1
	// ===------------------------===

		Log("\n [ 2 ] \n");
		Base2 B2;
		B2.Get_Base2();


	// 03. Dealing with Derived Class #1
	// ===---------------------------===

		Log("\n [ 3 ] \n");
		Derived1 D1;
		D1.Get_Der1(); D1.Get_Base1();


	// 04. Dealing with Derived Class #2
	// ===---------------------------===

		Log("\n [ 4 ] \n");
		Derived2 D2;
		D2.Get_Der2(); D2.Get_Base2();


	// 05. Dealing with Derived Class #3
	// ===---------------------------===

		Log("\n [ 5 ] \n");
		Derived3 D3;
		D3.Get_Der3();
		D3.Get_Base2(); D3.Get_Base1();


	// 06. Dealing with Derived Class #4
	// ===---------------------------===

		Log("\n [ 6 ] \n");
		Derived4 D4;
		D4.Get_Der4(); D4.Get_Der3();
		D4.Get_Base2(); D4.Get_Base1();
}
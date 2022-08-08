#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


class Base1
{
public:

	void Get_info_1()
	{
		Log("This is the Base #1 Class / Object");
	}
};

class Base2
{
public:

	virtual
	void Get_info_2()
	{
		Log("This is the Base #2 Class / Object");
	}
};

class Derived : public Base1, public Base2
{
public:

	void Get_info_1()
	{
		Log("This is the Derived Class / Object");
	}

	void Get_info_2() override
	{
		Log("This is the Derived Class / Object");
	}
};


int main()
{
	// 1. Dealing with Base #1
	// ===-----------------===

		Log("");
		Base1 B1;
		B1.Get_info_1();



	// 2. Dealing with Base #2
	// ===-----------------===

		Log("");
		Base2 B2;
		B2.Get_info_2();



	// 3. Dealing with Derived
	// (using Original Object)
	// ===-----------------===

		Log("");
		Derived D;
		D.Get_info_1();
		D.Get_info_2();


	// 3. Dealing with Derived
	//  (using Polymorphism)
	// ===-----------------===

		Log("");
		((Base1)D).Get_info_1();
		((Base2)D).Get_info_2();


	// 4. Dealing  with  Derived
	// (using pure Polymorphism)
	// ===-------------------===

		Log("");
		(*(Base1*)(&D)).Get_info_1();
		(*(Base2*)(&D)).Get_info_2();
}
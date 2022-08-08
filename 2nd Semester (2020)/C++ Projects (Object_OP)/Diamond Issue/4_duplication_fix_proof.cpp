#include<iostream>
#define Log(x) cout << x << endl
using namespace std;

class Base1
{
	string ID;

public:

	Base1() : ID("Base #1")
	{
		Log("C - Base #1");
	}

	void Get() const
	{
		Log("Get() - Base #1");
	}

	string Get_ID() const
	{
		return ID;
	}

	void Set(string&& S)
	{
		ID = S;
	}

	~Base1()
	{
		Log("D - Base #1");
	}
};


class Derived1 : virtual public Base1
{
	string ID;

public:

	Derived1() : ID("Derived #1")
	{
		Log("C - Derived #1");
	}

	void Get() const
	{
		Log("Get() - Derived #1");
	}

	string Get_ID() const
	{
		return ID;
	}

	void Set(string&& S)
	{
		ID = S;
	}

	~Derived1()
	{
		Log("D - Derived #1");
	}
};

class Derived2 : virtual public Base1
{
	string ID;

public:

	Derived2() : ID("Derived #2")
	{
		Log("C - Derived #2");
	}

	void Get() const
	{
		Log("Get() - Derived #2");
	}

	string Get_ID() const
	{
		return ID;
	}

	void Set(string&& S)
	{
		ID = S;
	}

	~Derived2()
	{
		Log("D - Derived #2");
	}
};


class Hybrid : public Derived1, public Derived2
{
	string ID;

public:

	Hybrid() : ID("Hybrid")
	{
		Log("C - Hybrid");
	}

	void Get() const
	{
		Log("Get() - Hybrid");
	}

	string Get_ID() const
	{
		return ID;
	}

	void Set(string&& S)
	{
		ID = S;
	}

	~Hybrid()
	{
		Log("D - Hybrid");
	}
};


int main()
{
	// Dealing with Base #1
	// =-----On Stack-----=
	// ==----------------==

		Log("\n\n[ 1 ] \n");
		Base1 B;
		B.Get();


	// Dealing with Derived #1
	// =------On Stack-------=
	// ==-------------------==

		Log("\n\n[ 2 ] \n");
		Derived1 D1;
		D1.Get();
		((Base1*)&D1)->Get();


	// Dealing with Derived #2
	// =------On Stack-------=
	// ==-------------------==

		Log("\n\n[ 3 ] \n");
		Derived2 D2;
		D2.Get();
		((Base1*)&D2)->Get();


	// Dealing with Hybrid
	// =----On Stack-----=
	// ==---------------==

		Log("\n\n[ 4 ] \n");
		Hybrid H;
		H.Get();
		((Derived1*)&H)->Get();
		((Base1*)((Derived1*)&H))->Get();
		((Derived2*)&H)->Get();
		((Base1*)((Derived2*)&H))->Get();

		( (Base1*)((Derived1*)&H) )->Set("Set() - Derived #1");
		( (Base1*)((Derived2*)&H) )->Set("Set() - Derived #2");

		Log("");
		Log( ((Base1*)((Derived1*)&H))->Get_ID() );
		Log( ((Base1*)((Derived2*)&H))->Get_ID() );



	// Destructors Time

		Log("\n\n[ Destructors ] \n");
}
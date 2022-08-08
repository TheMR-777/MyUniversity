#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


// Topic
// =====
// Multiple Inheritance

// How to Execute the Code
// =======================
// Please try not to use the "Run" Button above to run the code
// repl.it uses clang compiler, and this code is based on MinGW & MSVC
// Copy and paste the following command into the Right Terminal (without "//")
// g++ 'Presentation/Coding Tutorials/03.cpp' && ./a.out && rm a.out
// Then press Enter to Execute the executable file
// Have a Nice Coding


class Base1
{
protected:

	Base1()
	{
		Log("Base #1 - Constructor called!");
	}


	void Show_B1()
	{
		Log("Function called from Base #1");
	}


	~Base1()
	{
		Log("Base #1 - Destructor called!");
	}
};

class Base2
{
protected:

	Base2()
	{
		Log("Base #2 - Constructor called!");
	}


	void Show_B2()
	{
		Log("Function called from Base #2");
	}


	~Base2()
	{
		Log("Base #2 - Destructor called!");
	}
};

class Derived :protected Base1, protected Base2
{
public:

	Derived()
	{
		Log("Derived Class - Constructor called!");
	}


	void Show()
	{
		Log("Function called from Derived Class");
	}

	void Show_B1()
	{
		Base1::Show_B1();
	}

	void Show_B2()
	{
		Base2::Show_B2();
	}


	~Derived()
	{
		Log("Derived Class - Destructor called!");
	}

};


int main()
{
	// Initialization

		Derived D;
		Log("");

	// Function Calling

		D.Show();
		D.Show_B1();
		D.Show_B2();

	// Finalization

		Log("");
}
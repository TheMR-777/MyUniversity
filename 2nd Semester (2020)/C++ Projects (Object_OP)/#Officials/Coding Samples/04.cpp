#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


// Topic
// =====
// Casting & Polymorphism - Part #1
// (Stack Based)

// How to run the Code
// ===================
// Please try not to use the "Run" Button above to run the code
// repl.it uses clang compiler, and this code is based on MinGW & MSVC
// Copy and paste the following command into the Right Terminal (without "//")
// clear && g++ 'Presentation/Coding Tutorials/04.cpp' && ./a.out && rm a.out
// Then press Enter to Execute the executable file
// Have a Nice Coding


class Base1
{
  public:

    Base1()
    {
      Log(" Constructor - Base #1 Created!");
    }

    void Get_info()
    {
      Log(" This is Base #1 Class");
    }

    ~Base1()
    {
      Log(" Destructor - Base #1 Destructed!");
    }
};

class Base2
{
  public:

    Base2()
    {
      Log(" Constructor - Base #2 Created!");
    }

    void Get_info()
    {
      Log(" This is Base #2 Class");
    }

    ~Base2()
    {
      Log(" Destructor - Base #2 Destructed!");
    }
};

class Derived : public Base1, public Base2
{
	public:

		Derived()
		{
			Log(" Constructor - Derived Created!");
		}

		void Get_info()
		{
			Log(" This is Derived Class");
		}

		~Derived()
		{
			Log(" Destructor - Derived Destructed!");
		}
};



int main()
{
	// 1. Dealing with Base #1 Class
	// -----------------------------

		Log("");
		Base1 B1;
		B1.Get_info();


	// 2. Dealing with Base #2 Class
	// -----------------------------

		Log("");
		Base2 B2;
		B2.Get_info();


	// 3. Dealing with Derived Class
	// -----------------------------

		Log("");
		Derived D;
		D.Get_info();


	// 4. Using Polymorphism on Derived Class
	// --------------------------------------

		Log("");
		((Base1)D).Get_info();
		((Base2)D).Get_info();


	// 5. Using Pure Polymorphism on Derived Class
	// -------------------------------------------

		Log("");
		(*((Base1*)&D)).Get_info();
		(*((Base2*)&D)).Get_info();


	// Finalize
	// --------

		Log("");
}
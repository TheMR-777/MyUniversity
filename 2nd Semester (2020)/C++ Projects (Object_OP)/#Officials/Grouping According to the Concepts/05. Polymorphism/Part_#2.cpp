#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


// Topic
// =====
// Casting & Polymorphism - Part #2
// on Heap with Virtual Destructors

// How to run the Code
// ===================
// Please try not to use the "Run" Button above to run the code
// repl.it uses clang compiler, and this code is based on MinGW & MSVC
// Copy and paste the following command into the Right Terminal (without "//")
// clear && g++ 'Presentation/Coding Tutorials/05.cpp' && ./a.out && rm a.out
// Then press Enter to Execute the executable file
// Have a Nice Coding

class Base1
{
  public:

    Base1()
    {
      Log("- Constructor - Base #1 Created!");
    }

    void Get_info()
    {
      Log("> This is Base #1 Class");
    }

    virtual
    ~Base1()
    {
      Log("- Destructor - Base #1 Memory Freed!");
    }
};

class Base2
{
  public:

    Base2()
    {
      Log("- Constructor - Base #2 Created!");
    }

    void Get_info()
    {
      Log("> This is Base #2 Class");
    }

    virtual
    ~Base2()
    {
      Log("- Destructor - Base #2 Memory Freed!");
    }
};

class Derived : public Base1, public Base2
{
	public:

		Derived()
		{
			Log("- Constructor - Derived Created!");
		}

		void Get_info()
		{
			Log("> This is Derived Class");
		}

		~Derived()
		{
			Log("- Destructor - Derived Memory Freed!");
		}
};



int main()
{

	// 1. Dealing with Base #1 Class
	// -----------------------------

		Log("\n [ 1 ] \n");
		Base1* B1 = new Base1();
		B1->Get_info();
		delete B1;


	// 2. Dealing with Base #2 Class
	// -----------------------------

		Log("\n [ 2 ] \n");
		Base2* B2 = new Base2();
		B2->Get_info();
		delete B2;


	// 3. Dealing with Derived Class
	// -----------------------------

		Log("\n [ 3 ] \n");
		Derived* D = new Derived();
		D->Get_info();
		delete D;


	// 4. Using Polymorphism on Derived Class
	//    Casting into Base #1
	// --------------------------------------

		Log("\n [ 4 ] \n");
		B1 = new Derived();
		B1->Get_info();
		delete B1;


	// 5. Using Polymorphism on Derived Class
	//    Casting into Base #2
	// --------------------------------------

		Log("\n [ 5 ] \n");
		B2 = new Derived();
		B2->Get_info();
		delete B2;


	// 6. Using Pure Polymorphism on Derived Class
	// -------------------------------------------

		Log("\n [ 6 ] \n");
		((Base1*)D)->Get_info();
		((Base2*)D)->Get_info();



  // Finalize
	// --------

		Log("");
}
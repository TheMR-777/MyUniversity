#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


// Topic
// =====
// Pure Polymorphism - Part #3
// on Stack with Virtual Destructors
// and constant functions

// How to run the Code
// ===================
// Please try not to use the "Run" Button above to run the code
// repl.it uses clang compiler, and this code is based on MinGW & MSVC
// Copy and paste the following command into the Right Terminal (without "//")
// clear && g++ 'Presentation/Coding Tutorials/06.cpp' && ./a.out && rm a.out
// Then press Enter to Execute the executable file
// Have a Nice Coding

// How to test the Polymorphism
// ============================
// Un-comment the Comment lines in the main() to test the existance of
//  objects in multiple forms (which is called Polymorphism).
// Do this in your IDEs, please don't change the code from here, as
//  it's for all the students.
// Close the sections of classes, to make the code more readable



class Base1
{
  public:

    Base1()
    {
      Log("- Constructor - Base #1 Created!");
    }

    void Get_info() const
    {
      Log("> This is Base #1 Class");
    }

    virtual
    ~Base1()
    {
      Log("- Destructor - Base #1 Destructed!");
    }
};

class Base2
{
  public:

    Base2()
    {
      Log("- Constructor - Base #2 Created!");
    }

    void Get_info() const
    {
      Log("> This is Base #2 Class");
    }

    virtual
    ~Base2()
    {
      Log("- Destructor - Base #2 Destructed!");
    }
};

class Derived1 : public Base1
{
	public:

		Derived1()
		{
			Log("- Constructor - Derived #1 Created!");
		}

		void Get_info() const
		{
			Log("> This is Derived #1 Class");
		}

		~Derived1()
		{
			Log("- Destructor - Derived #1 Destructed!");
		}
};

class Derived2 : public Base2
{
	public:

		Derived2()
		{
			Log("- Constructor - Derived #2 Created!");
		}

		void Get_info() const
		{
			Log("> This is Derived #2 Class");
		}

		~Derived2()
		{
			Log("- Destructor - Derived #2 Destructed!");
		}
};

class Derived3 : public Base1, public Base2
{
	public:

		Derived3()
		{
			Log("- Constructor - Derived #3 Created!");
		}

		void Get_info() const
		{
			Log("> This is Derived #3 Class");
		}

		~Derived3()
		{
			Log("- Destructor - Derived #3 Destructed!");
		}
};



void Printer1(const Base1& B1)
{
    B1.Get_info();
}

void Printer2(const Base2& B2)
{
    B2.Get_info();
}



int main()
{
    // Dealing with Derived #1
    // -----------------------

        Log("");
        Derived1 D1;
        D1.Get_info();
        Printer1(D1);
        // Printer2(D1); // Not Possible


    // Dealing with Derived #2
    // -----------------------
    
        Log("");
        Derived2 D2;
        D2.Get_info();
        // Printer1(D2); // Not Possible
        Printer2(D2);


    // Dealing with Derived #3
    // -----------------------
    
        Log("");
        Derived3 D3;
        D3.Get_info();
        Printer1(D3);
        Printer2(D2);


    // Finalize

        Log("");
}
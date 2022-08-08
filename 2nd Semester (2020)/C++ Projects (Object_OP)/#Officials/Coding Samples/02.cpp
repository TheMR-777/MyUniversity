#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


// Topic
// =====
// Generalization & Specialization
//
// How to Execute the Code
// =======================
// Please try not to use the "Run" Button above to run the code
// repl.it uses clang compiler, and this code is based on MinGW & MSVC
// Copy and paste the following command into the Right Terminal (without "//")
// clear && g++ 'Presentation/Coding Tutorials/02.cpp' && ./a.out && rm a.out
// Then press Enter to Execute the executable file
// Have a Nice Coding


class Person
{
	protected:

		string m_Name, m_Gender;
		int m_Age;

		Person(string& n, string& g, int& a)
			: m_Name(n), m_Gender(g), m_Age(a)
		{
			Log("Constructor - Person Created!");
		}

		void Get_info()
		{
			Log("Name of the Person   : " << m_Name);
			Log("Age of the Person    : " << m_Age);
			Log("Gender of the Person : " << m_Gender);
		}

		~Person()
		{
			Log("Destructor - Person Destroyed!");
		}
};

class Doctor : public Person
{
  public:

    Doctor(string&& n, string&& g, int&& a)
      : Person(n, g, a)
    {
      Log("Constructor - Doctor Created!");
    }

    void Get_info()
    {
      Person::Get_info();
    }

    ~Doctor()
    {
      Log("Destructor - Doctor Destructed!");
    }
};

class Teacher : public Person
{
  public:

    Teacher(string&& n, string&& g, int&& a)
      : Person(n, g, a)
    {
      Log("Constructor - Teacher Created!");
    }

    void Get_info()
    {
      Person::Get_info();
    }

    ~Teacher()
    {
      Log("Destructor - Teacher Destructed!");
    }
};

class Student : public Person
{
  public:

    Student(string&& n, string&& g, int&& a)
      : Person(n, g, a)
    {
      Log("Constructor - Student Created!");
    }

    void Get_info()
    {
      Person::Get_info();
    }

    ~Student()
    {
      Log("Destructor - Student Destructed!");
    }
};



int main()
{
	// Dealing with Student

		Log("");
		Student S("Connor", "Male", 19);
		S.Get_info();

	// Dealing with Teacher

		Log("");
		Teacher T("Bogdan", "Male", 35);
		T.Get_info();

	// Dealing with Doctor

		Log("");
		Doctor D("Hanz", "Male", 39);
		D.Get_info();

	// Finalize

		Log("");
}
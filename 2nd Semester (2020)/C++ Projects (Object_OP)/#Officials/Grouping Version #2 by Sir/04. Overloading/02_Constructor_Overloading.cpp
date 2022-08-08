#include <iostream>
#define Log(x) cout << x << endl

using namespace std;

class Person
{
	string m_Name;
	int m_Age;

public:

	Person() = default;


	Person(string n)
	{
		m_Name = n;
	}

	Person(int g)
	{
		m_Age = g;
	}

	Person(string n, int g)
	{
		m_Name = n;
		m_Age = g;
	}



	void set_Cred(string n)
	{
		m_Name = n;
	}

	void set_Cred(int g)
	{
		m_Age = g;
	}

	void set_Cred(string n, int g)
	{
		m_Name = n;
		m_Age = g;
	}


	void Print()
	{
		Log("Name : " << m_Name);
		Log("Age  : " << m_Age);
	}
};


int main()
{
	// 01. Person #1
	// =-----------=

		Log("");
		Person P1("EG");
		P1.set_Cred(19);
		P1.Print();


	// 02. Person #2
	// =-----------=

		Log("");
		Person P2("SS", 19);
		P2.Print();


	// 03. Person #3
	// =-----------=

		Log("");
		Person P3(19);
		P3.set_Cred("MR");
		P3.Print();





	// >==--------===--------==< \\
	// | Alternative Technique | \\
	// >==--------===--------==< \\

		Log("");
		Person("MG", 17).Print();
}
#include <iostream>
#define Log(x) cout << x << endl

using namespace std;

class Person
{
	string m_Name;
	int m_Age;

public:

	Person() = default;

	void Print()
	{
		Log("Name : " << m_Name);
		Log("Age  : " << m_Age);
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
};


int main()
{
	// 01. Person #1
	// =-----------=

		Log("");
		Person P1;
		P1.set_Cred("MG");
		P1.set_Cred(19);
		P1.Print();


	// 02. Person #2
	// =-----------=

		Log("");
		Person P2;
		P2.set_Cred("SS", 19);
		P2.Print();
}
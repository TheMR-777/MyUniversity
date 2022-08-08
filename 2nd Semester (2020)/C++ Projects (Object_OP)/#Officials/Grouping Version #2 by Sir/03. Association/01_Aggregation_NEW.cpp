#include <iostream>
#include <array>

using namespace std;
#define Log(x) cout << x << endl


struct Subject
{
	string m_Name;
	string m_Code;

	Subject(string name, string code) 
	{
		m_Name = name, m_Code = code;
	}
};

class Student
{
	string m_Name{ "NoName" };
	string m_Roll{ "NULL" };
	Subject* m_Subjects[3];

public:


	void set_Cred(string n, string r)
	{
		m_Name = n;
		m_Roll = r;
	}

	void add_Subject(int count, string name, string code)
	{
		m_Subjects[count] = new Subject(name, code);
	}

	void Print()
	{
		cout << "Name: " << m_Name << " " << m_Roll << endl;
		cout << "Subjects: ";
		for (auto& sub : m_Subjects)
		{
			cout << sub->m_Name << " ";
		}
	}
};

int main()
{
	// Initializing Students

	Student S1;
	S1.set_Cred("Agent", "47");
	S1.add_Subject(0, "Math", "CS_M201");
	S1.add_Subject(1, "Physics", "CS_P202");
	S1.add_Subject(2, "Psychology", "PS_M404");

	S1.Print();
}
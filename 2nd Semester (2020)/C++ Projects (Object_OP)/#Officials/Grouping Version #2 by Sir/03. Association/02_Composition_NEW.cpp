#include <iostream>
#include <array>

using namespace std;
#define Log(x) cout << x << endl


class Subject
{
	string m_Name;
	string m_Code;

public:

	Subject() = default;

	void Set(string n, string c)
	{
		m_Name = n;
		m_Code = c;
	}
};

class Student
{
	string m_Name;
	string m_Roll;
	array<Subject, 3> Subjects;

public:


	void set_Cred(string n, string r)
	{
		m_Name = n;
		m_Roll = r;
	}

	void set_Subject(int i, string n, string c)
	{
		if (i >= 0 && i < Subjects.size())
		{
			Subjects[i].Set(n, c);
		}
	}
};

int main()
{
	// Initializing Students

	Student S1;
	S1.set_Cred("EG", "47");
	S1.set_Subject(0, "Math", "CS_M201");
	S1.set_Subject(1, "Physics", "CS_P202");
	S1.set_Subject(2, "Psychology", "PS_M404");
}
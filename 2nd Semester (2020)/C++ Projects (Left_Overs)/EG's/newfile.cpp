#include <iostream>

class Student
{
	private:
	int age;
	public:
	int getage()
	{
		return age;
	}
	void setage(int a)
	{
		age=a;
	}
};
int main()
{
	Student st;
	int a;
	getline(cin,a);
	st.setage(a);
	cout<<st.getage();
}	


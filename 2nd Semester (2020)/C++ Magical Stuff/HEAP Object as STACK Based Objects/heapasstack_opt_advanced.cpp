#include <iostream>
using namespace std;

class Person
{
	string fName, lName; int age;

	public:
	
		Person(string f, string l, int a)
			: fName(f), lName(l), age(a) {}

		void Print()
		{
			cout << "1st_Name : [ " << fName << " ]" << endl;
			cout << "2nd_Name : [ " << lName << " ]" << endl;
			cout << "My_AGE   : [ " << age << " ]" << endl;
		}
};



int main()
{
	// Allocating on HEAP, and making it STACK Based!
	
		Person &Me_on_HEAP = *(new Person("Muhammad", "MR", 19));

	// Showing results

		Me_on_HEAP.Print();

	// Deleting

		delete &Me_on_HEAP;
}
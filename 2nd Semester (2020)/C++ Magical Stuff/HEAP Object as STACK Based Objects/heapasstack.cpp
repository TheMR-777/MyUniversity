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
	// Allocating on HEAP
	
		Person* Me_on_HEAP = new Person("Muhammad", "MR", 19);

	// Making it STACK based somehow
    // with taking care of memory as well

		Me_on_HEAP->Print();
        (*Me_on_HEAP).Print();

		Person &Me_Also = *Me_on_HEAP;

		Me_Also.Print();

	// Deleting

		delete Me_on_HEAP;
		// delete &Me_Also;
}
 
#include <iostream>
using namespace std;
//static data member concept
 // Command to run this :
// clear && g++ 'Concepts/2.1.cpp' && ./a.out && rm a.out
class Student
{
	private:	
		static int  noOfStudents;//static data members

	public:
		static void fun()
		{
			cout <<"Value of  no Of Students is: " << noOfStudents  << endl;
		}
};

//defining
int Student::noOfStudents = 0;
/*private static member cannot be accessed outside the class except for
initialization*/ 


int main()
{
	Student S;

	S.fun();
	
	return 0;
}

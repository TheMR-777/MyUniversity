
#include <iostream>
using namespace std;
//static data member access using :: operator concept
 // Command to run this :
// clear && g++ 'Concepts/1.9.cpp' && ./a.out && rm a.out

class Student
  {
	
  public: 
  static int noOfStudents;// staticdata member
};
 int Student::noOfStudents;//definition
int main()
{
Student aStudent;
aStudent.noOfStudents = 1;
Student::noOfStudents = 1;// accessing in main using scope resolution operator
cout<< "the value initiallized in main function for static data member is: "<< Student::noOfStudents;
return 0;
} 

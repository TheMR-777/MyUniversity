
#include <iostream>
using namespace std;

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

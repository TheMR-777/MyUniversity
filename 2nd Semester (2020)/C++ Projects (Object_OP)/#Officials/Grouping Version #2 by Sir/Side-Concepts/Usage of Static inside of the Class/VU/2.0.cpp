#include <cstdlib>
#include <iostream>
using namespace std;
//life of static data members (They remain in memory even when all Objects of a class are destroyed )
//They can be used to store information that is required by all objects, like global
//variables
 // Command to run this :
// clear && g++ 'Concepts/2.0.cpp' && ./a.out && rm a.out
class Student
{
public:
 static int noOfStudents;
 Student();
 ~Student();
};
int Student::noOfStudents = 0; 
Student::Student()//body of constructor outside the class
{
 noOfStudents++;
}
Student::~Student()//body of distructor outside the class
{
 noOfStudents--;
}
 
int main()
{
 cout <<Student::noOfStudents <<endl;
 Student studentA;
 cout <<Student::noOfStudents <<endl;
 Student studentB;
 cout <<Student::noOfStudents <<endl;
 return 0;
}

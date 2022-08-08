#include <cstdlib>
#include <iostream>
using namespace std;
class Student{
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

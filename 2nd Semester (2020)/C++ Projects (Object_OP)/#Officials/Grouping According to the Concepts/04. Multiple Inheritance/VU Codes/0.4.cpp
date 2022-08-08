#include<iostream>
using namespace std;
class Student{
	public:
int rollNo;
void setRollNo(int aNo)
{
	cout<<"Roll Number is"<<aNo;
}
 };
 int main()
 {
 	Student aStudent;
 aStudent.setRollNo(5);// access through dot
 cout<<"\n";
 Student *ptr_student = new Student();
 ptr_student->setRollNo(5);// access through arrow

 }
 

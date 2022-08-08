#include <iostream>
using namespace std;
class Student
{
public:
	int RollNo;
 
 void setRollNo(int aNo)
 {
 	RollNo=aNo;
 	cout<<"i am the function accessed by the pointer to object\n my value is : "<<RollNo<<endl;
 }
};

int main(){
 Student obj;
 Student *ptr;// Declare pointer to a class.
 ptr = &obj;//Save the address of  object
 ptr->setRollNo(10);// Now try to access a member using member access operator
 return 0;
} 

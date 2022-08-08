#include <iostream>
using namespace std;
//pointer to object: This Pointer is a constant pointer that holds the memory address of the current object
 // Command to run this :
// clear && g++ 'Concepts/2.2.cpp' && ./a.out && rm a.out
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

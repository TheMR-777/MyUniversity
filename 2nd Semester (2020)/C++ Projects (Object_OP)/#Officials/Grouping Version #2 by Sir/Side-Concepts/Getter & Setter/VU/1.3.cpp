#include <iostream>
using namespace std;
//getter setter concept
 // Command to run this :
// clear && g++ 'Concepts/1.3.cpp' && ./a.out && rm a.out
class Student
{
	int rollNo;
public:

 void setRollNo(int aRollNo)
 {
 
 if(aRollNo < 0)
 {
 rollNo = 0;
 cout<<"hello i am setter: \nyou set the value of roll number: "<<rollNo<<endl;
 }
 else
 {
 rollNo = aRollNo;
 	cout<<"hello i am setter: \nyou set the value of roll number: "<<rollNo<<endl;
 }
 
 }
 int getRollNo(){
 return rollNo;
 }
};
int main()
{
	int recieve;
	Student S;
	S.setRollNo(11);
	recieve=	S.getRollNo();
	cout<<"hello i recieved the value in main from the getter: \nthe roll number is: "<<recieve<<endl;

	
}

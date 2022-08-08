#include <iostream>
using namespace std;
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

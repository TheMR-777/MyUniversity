#include<iostream>
using namespace std;
class Student{
int rollNo;
public:
void setRollNo(int aRollNo)// drfining func inside the class
{
 rollNo = aRollNo;
 cout<<"roll number is: "<<rollNo<<endl;
}
};
int main()
{
	Student S;
    S.setRollNo(47);// accessing the function and passing it the argument
}

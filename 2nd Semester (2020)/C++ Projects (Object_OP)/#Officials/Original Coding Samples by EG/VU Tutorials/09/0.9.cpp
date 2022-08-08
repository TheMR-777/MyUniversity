#include<iostream>
using namespace std;
class Student1{
int rollNo;
public:
inline void setRollNo(int aRollNo);// making function inline  inside the class
};
void Student1::setRollNo(int aRollNo)// func definition outside the class
{
 rollNo = aRollNo;
  cout<<" i am roll No "<<rollNo<<" from the inline function inside the class\n";
}
class Student2{
	int rollNo;
public:
void setRollNo(int aRollNo);
};
inline void Student2::setRollNo(int aRollNo)// making function inline  outside the class
{
 rollNo = aRollNo;
 cout<<" i am roll No "<<rollNo<<" from the inline function outside the class\n";
}
 int main()
 {
 	Student1 S1;
 	S1.setRollNo(41);
 	Student2 S2;
 	S2.setRollNo(23);
 }

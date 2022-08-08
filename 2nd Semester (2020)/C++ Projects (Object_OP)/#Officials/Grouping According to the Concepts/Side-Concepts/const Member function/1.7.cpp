 
#include <iostream>
using namespace std;
//const object and member function concept
 // Command to run this :
// clear && g++ 'Concepts/1.7.cpp' && ./a.out && rm a.out
class Student
{
 int rollNo;
public:

 Student(int aRollNo) : rollNo(aRollNo)
  {

  }

 int getRollNo() const// const member function
 {
 return rollNo;
 }
};
int main(){
 const Student aStudent(5); // const object
 int const a = aStudent.getRollNo();
 cout<<" the value returned from const type getter is: "<< a<<endl;
 system("PAUSE");
 return EXIT_SUCCESS;
} 

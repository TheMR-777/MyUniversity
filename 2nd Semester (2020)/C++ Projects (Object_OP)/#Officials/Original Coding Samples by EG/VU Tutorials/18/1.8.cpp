 
 #include <cstdlib>
#include <iostream>
using namespace std;
class Student{
 int rollNo;
public:

 Student(int aRollNo) : rollNo(aRollNo)
  {

  }

 int getRollNo() const
 {
 return rollNo;
 }
};
int main(){
 const Student aStudent(5);
 int const a = aStudent.getRollNo();
 cout<<" the value returned fron const type getter is: "<< a<<endl;
 system("PAUSE");
 return EXIT_SUCCESS;
} 

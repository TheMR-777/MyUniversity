#include <iostream>
#include<string>
using namespace std;

//copy constructor concept
 // Command to run this :
// clear && g++ 'Concepts/1.2.cpp' && ./a.out && rm a.out

class Student
{
 string  name;
 int rollNo;
public:
 Student(string aName, int arollNo)
 {
 name =  aName;
 rollNo = arollNo;

 }
 Student(const Student &obj)   /* A copy constructor is a member function which initializes an object 
                                      using another object of the same class.*/
 {

 name = obj.name;
 
 rollNo = obj.rollNo;


 }

 void showName()
 {
 cout<<name<<endl;

 }
 ~Student()
 {
         
 }
};
int main()
{
	Student studentA("AHMAD",1); 
 {
 Student studentB = studentA;
 /*copy constructor is implicitly called at this point*/
 }
 studentA.showName();

 system("pause");
 return 0; 
}

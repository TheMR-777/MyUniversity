#include<iostream> 
using namespace std; 
  
class Student
{ 
private: 
  int rollNo; 
  string Name; 
public: 
  Student(int aRollNo = 0, string aName ="Abc") 
  { 
  this->rollNo = aRollNo; 
  this->Name = aName; 
  } 
  Student &setRollNo(int r)
   {
     rollNo = r;
	 return *this;
   } 
  Student &setName(string n) 
  {
   Name = n; 
   return *this; 
   } 
  void print() 
  { 
  cout << "RollNo is = " << rollNo << " Name is = " << Name << endl;
   } 
}; 
  
int main() 
{ 
  Student S1(47, "grey"); 
  
  // Chained function calls.  All calls modify the same object 
  // as the same object is returned by reference 
  S1.setRollNo(10).setName("Anna"); 
   
  
  S1.print(); 
  return 0; 
} 

#include <iostream>
using namespace std;
// constructor and distructor concept
 // Command to run this :
// clear && g++ 'Concepts/1.1.cpp' && ./a.out && rm a.out
class Student
{ 
public: 
string name;
 Student(char * aName)
{
	 name= aName;
 cout << aName << " Constructor\n";

 }
  ~Student(){
 cout << name << " Destructor\n";
 }
};
 
 
int main()
{
 Student studentB("Ali");
 Student studentA("Ahmad");
 return 0;
} 

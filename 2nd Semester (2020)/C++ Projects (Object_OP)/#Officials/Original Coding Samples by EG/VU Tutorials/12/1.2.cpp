#include <iostream>
using namespace std;
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

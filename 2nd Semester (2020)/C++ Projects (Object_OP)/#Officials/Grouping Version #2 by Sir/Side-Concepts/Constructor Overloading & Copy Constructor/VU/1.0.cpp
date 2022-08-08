#include <iostream>
#include <cstring>
using namespace std;
class Student{
 char * name;
 int rollNo;
public:
 Student(char * aName, int arollNo){
 name =  aName;
 strcpy(name,aName); 
 rollNo = arollNo;

 }
 Student(const Student &obj){
 name = obj.name;
 rollNo = obj.rollNo;


 }
 void showName(){
 cout<<name<<endl;

 }
 ~Student(){

 delete []name;

 }
};
int main()
{
 Student studentA("AHMAD",1);
 Student studentB = studentA;
 /*copy constructor is implicitly called at this point*/

 studentA.showName();
 studentB.showName();
 system("pause");
 return 0;
} 

#include <iostream>
#include<cstring>
using namespace std;
class Student{
 char * name;
 int rollNo;
public:
 Student(char * aName, int arollNo){
 name = new char[strlen(aName)+1];
 strcpy(name,aName);
 rollNo = arollNo;

 }
 Student(const Student &obj){

 name = new char[strlen(obj.name)+1];
 strcpy(name,obj.name);
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
 {
 Student studentB = studentA;
 /*copy constructor is implicitly called at this point*/
 }
 studentA.showName();

 system("pause");
 return 0; 
}

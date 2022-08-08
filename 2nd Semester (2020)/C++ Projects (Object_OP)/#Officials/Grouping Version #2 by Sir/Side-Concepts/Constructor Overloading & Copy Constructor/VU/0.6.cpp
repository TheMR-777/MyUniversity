#include<iostream>
using namespace std;
class Student{
 int rollNo;
 char *name;
 float GPA;
public:
 Student() /* explicit default constructor */
 {
 	cout<<"i am default constructor\n";
 }
 Student(char * aName) // constructor with one parameter
 {
 	cout<<" i am the constructor overloaded with a name\n";
 	name= aName;
 	cout<<name;
 }
 Student(char * aName, int aRollNo) /* constructor with two parameters */
 { 
    cout<<"i am constructor overloaded with a name and a roll number\n";
    	name= aName;
 	cout<<name<<endl;
 	rollNo=aRollNo;
 	cout<<rollNo<<endl;
 }
 Student(char * aName, int aRollNo, float aGPA) /* constructor with three
parameters */
{
   cout<<"i am constructor overloaded with a name a roll number and GPA\n";
   name= aName;
 	cout<<name<<endl;
 	rollNo=aRollNo;
 	cout<<rollNo<<endl;
 	GPA=aGPA;
 	cout<<GPA<<endl;
 }
};
 
 int main()
{
  Student student1();	// default constructor

//Student student2( "Elsa" );  // romove comment lines to run this constructor
 
// Student student3( "Elsa", 1 );  romove comment lines to run this constructor
// Student student4( "Elsa", 1 , 4.0);  romove comment lines to run this constructor 
} 

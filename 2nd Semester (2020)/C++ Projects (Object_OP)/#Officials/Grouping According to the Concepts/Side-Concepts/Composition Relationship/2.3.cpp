# include<iostream>
#include <string>
using namespace std;
//composition (making objrct of one class in another class) concept
 // Command to run this :
// clear && g++ 'Concepts/2.3.cpp' && ./a.out && rm a.out
 class Date
 {
 	public:
 		int day, month, year;
 		Date(int a, int b, int c)
 		{
 			day=a;
 			month=b;
 			year=c;
 			cout<<"i am Date constructor called and overloaded in Student Class: "<<day<<"/"<<month<<"/"<<year<<endl;
		}
		  
 };
 class Student
 {    
     
 	public:
 	  string name;
 	  Student(int a, int b, int c)
 	   
 		{
 		
 		 	Date D(a,b,c);
 		 
		}
		
 };
 int main()
 {
 	Student S (02,02,2000);
 	
 	
 }

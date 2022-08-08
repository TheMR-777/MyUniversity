#include<iostream>
#include<cstring>
using namespace std;
class String
{
 int size;  
char * bufferPtr;
public:
 String(); // default constructor
 String(char *); // overloaded constructor
 String &operator = (const String & rhs); //copy constructor & assignment operator overloading

 

};
String::String()
{
 bufferPtr = NULL;
 size = 0;
}
String::String(char * ptr)
{
 if(ptr != NULL){
 size = strlen(ptr);
 bufferPtr = new char[size+1];
 strcpy(bufferPtr, ptr);
 //cout<<"the value of the obj is: "<<bufferPtr<<endl;
 } 
 else{
 bufferPtr = NULL;
size = 0;
}
} 
String & String :: operator = (const String & rhs)
{
 if(this != &rhs)// check if lvalue and r value are not same
 {
     // deleting memory of left hand side operand
 size = rhs.size;
 delete [] bufferPtr; 
 if(rhs.bufferPtr != NULL)
 {
     // memory allocation
 bufferPtr = new char[rhs.size+1];
 strcpy(bufferPtr,rhs.bufferPtr);
 cout<<"new memory is alocated \n";
 
 }
 }
 else 
 {
     bufferPtr = NULL;
     cout<<"the left had value and right hand value both are same\n";
 }
 return *this;

}

int main()
 {
 String str1("brother");
  str1 = str1;
 return 0;
} 
 
 

 
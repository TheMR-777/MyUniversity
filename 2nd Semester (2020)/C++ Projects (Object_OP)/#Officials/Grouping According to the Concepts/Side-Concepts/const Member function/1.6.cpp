 #include<iostream> 
using namespace std; 
  //const member function concept
 // Command to run this :
// clear && g++ 'Concepts/1.6.cpp' && ./a.out && rm a.out
class Student 
{ 
    string Name; 
public: 
    Student(string aName = "abc")
	 {
	 Name=aName;
	 } 
      
    // We get compiler error if we add a line like "value = 100;" 
    // in this function. 
    string getName() const // const member function 
	{
	return Name;
	}   
}; 
  
int main()
 { 
  
    Student S("Anna"); 
    cout<<"you entered "<<S.getName(); 
} 

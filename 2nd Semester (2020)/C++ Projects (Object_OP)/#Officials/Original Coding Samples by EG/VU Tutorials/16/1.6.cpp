 #include<iostream> 
using namespace std; 
  
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
    string getName() const 
	{
	return Name;
	}   
}; 
  
int main()
 { 
  
    Student S("Anna"); 
    cout<<"you entered "<<S.getName(); 
} 

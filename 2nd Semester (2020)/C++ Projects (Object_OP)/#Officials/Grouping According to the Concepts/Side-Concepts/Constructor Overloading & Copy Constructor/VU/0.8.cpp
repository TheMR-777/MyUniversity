#include <iostream>
using namespace std;
class Student{
 int rollNo;
public:
Student(){
 rollNo = 0;
 cout<<"I am default constructor of Student class…\n";
 }
Student(const Student &obj){
 cout<<"I am copy constructor of Student class\n";
 rollNo = obj.rollNo;

}
};
int main()
{
 Student aStudent;
 /*default constructor is implicitly called at this point*/
 Student bStudent = aStudent;
 /*copy constructor is implicitly called at this point*/
system("pause");
}

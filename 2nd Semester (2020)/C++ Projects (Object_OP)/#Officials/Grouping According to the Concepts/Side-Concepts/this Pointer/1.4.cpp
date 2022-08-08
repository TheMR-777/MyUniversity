 #include <iostream>
using namespace std;
//Use of "this" concept
 // Command to run this :
// clear && g++ 'Concepts/1.4.cpp' && ./a.out && rm a.out
class Student
 {
private:
  int Num;
  string Name;
public:
  void setValues(int aNum, string aName)
  {
    this->Num =aNum;
    this->Name=aName;
  }
  void displayValues()
  {
    cout<<Num<<endl;
    cout<<Name;
  }
};
int main()
{
  Student S;
  S.setValues(77, "MG");
  S.displayValues();
  return 0;
}

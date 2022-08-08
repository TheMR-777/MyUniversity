#include<iostream>
using namespace std;
// freind class concept
 // Command to run this :
// clear && g++ 'Concepts/2.6.cpp' && ./a.out && rm a.out
class X
{
 friend class Y;// class Y is friend of class X
 private:
 int x_var1, x_var2;
 };
class Y
{
 private:
 int y_var1, y_var2; 
 X objX;   // class Y can access complete class X as Y is freinf of X
 public:
 void setX(){
 objX.x_var1 = 1; // intializing private memberas of X class in Y class
 objX.x_var2=2;  // intializing private memberas of X class in Y class
  cout<<"the value of x_var1 is set in Y class: "<<objX.x_var1<<endl;
   cout<<"the value of x_var2 is set in Y class: "<<objX.x_var2<<endl;
 }
 };
int main()
{
 Y objY;
 objY.setX();
 return 0;
 }

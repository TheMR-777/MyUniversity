#include <iostream>
using namespace std;
class Complex
{
    private: 
 double real, img;
public:
Complex(double r = 0, double i =0) 
	 
	 {
	  real = r; 
	  img = i;
	 } 
 bool operator == (const Complex & c);
//friend bool operator == (const //Complex & c1, const Complex & c2);
 bool operator != (const Complex & c);
//friend bool operator != (const //Complex & c1, const Complex & c2);

};
bool Complex::operator ==(const Complex & c)
{
 if((real == c.real) && (img == c.img))
 {
     return true;
 }
 else
 return false;
} 
 bool Complex::operator !=(const Complex & c){
 if((real != c.real) ||(img != c.img)){
 return true;
 }
 else
 return false;
} 
int main()
{
  bool a,b;
    Complex c1(12,14),c2(12,11);
    a=c1==c2;
    if(a==false)
    {
        cout<<"the Equality operator called and c1==c2 is wrong statement\n";
    }
    else
    {
    	cout<<"the eqality operator callied and statement c1==c2 is correct\b";
	}
    b=c1!=c2;
    if(b==true)
    {
      cout<<"the inequality operator called and c1!=c2 is right statement\n";
    }
    else
    {
    	cout<<"the inequality operator called and c1!=c2 is wrong statement\n";
	}
    
}

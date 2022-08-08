
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
     void display()
     {
     cout<<real<<"+"<<img<<"i"<<endl;
     }
Complex & operator+=(const Complex & rhs);
Complex & operator+=(const double & rhs);
};
Complex & Complex::operator += (const Complex & rhs)
{
 real = real + rhs.real;
 img = img + rhs.img;
 return * this;
}
Complex & Complex::operator += (const double & rhs)
 {
 real = real + rhs;
 return * this;
 }
int main()
{
    float a,b;
 Complex c1(11,12), c2(13.4,10.6), c3(9.0,8.7);
  c1 += c2;
  c3 += 0.087;
 c3.display();
 
 return 0;
} 

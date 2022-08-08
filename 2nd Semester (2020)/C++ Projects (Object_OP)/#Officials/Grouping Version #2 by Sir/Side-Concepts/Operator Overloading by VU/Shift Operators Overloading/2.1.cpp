
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
     
    friend ostream &operator<<( ostream &output, const Complex &num)
     { 
         output << "real : " << num.real << " Imag : " << num.img;
         return output;            
      }

        friend istream &operator >>( istream &input,  Complex &num )
      { 
        input >> num.real >> num.img;
         return input;            
      }

};
 
int main()
{ 
 Complex c1(11,12), c2(13,14),c3;
 cout<<"please enter the real and then imaginary part of your complex number\n";
 cin>>c3;
  cout << c1 << endl << c2 <<endl;
  cout<<c3;
  
 
 return 0;
} 
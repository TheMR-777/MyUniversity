#include<iostream>
#include<vector>
#include <string>
using namespace std;
class Energy
{
     public:
     

    float Calc(float &mass,int &a, float g=9.8)
    { 
      if(a!=1) 
      {
         cout<<"you did not enter value of g so by default the value of g is 9.8 m/s.\n";
         return (mass*g);
      }
     
      else 
      {
          
          return (mass*g);
      } 
    } 
    float Calc(float &weight,bool &D, float height=0)
    { 
      if(D==0) 
      {
         cout<<"Since the obj is on earth so by default\n";
         cout<<"      the value of height is 0.\n";
         cout<<endl;
         cout<<"the value of P.E is: ";
         return (weight*height);
      }
     
      else 
      {
          return (weight*height);
      } 
    } 

};
int main()
{
    cout<<"+------------------------------------------------------------------------+\n";
    cout<<"      This the is Question 2 THE FUNCTION OVERLOADING.                   |\n";
    cout<<"+------------------------------------------------------------------------+\n";
    cout<<"           *******************************                                \n";
     
     int a;
    float weight,height,g,mass;
    bool D;
    Energy E;
    cout<<"please enter the mass of the object.\n";
    cin>>mass;
    cout<<endl;
    cout<<" please enter 1 if you want to enter the value of accelaration due to  \n";
    cout<<"           gravity else enter any other integer.\n";
    cin>>a;
   if(a==1)
   {
       cout<<" please enter the value of g to get       \n";
       cout<<"      the weight of object.\n";
       cin>>g;
       weight= E.Calc(mass,a,g);
              
       cout<<"               The weight of the body is: "<<weight<<endl;
   }
    else
    {
       weight= E.Calc(mass,a);
             
         cout<<"               The weight if the body is: "<<weight<<endl;
  
    }
    cout<<"--------------------------------------------------------------------------\n";
    cout<<" please enter 0 if object is on the earth.\n";
    cout<<"       else enter any other integer.\n";
    cin>>D; cin.clear(); cin.sync();
    if(D==0)
    {
      cout<<E.Calc(weight,D);
      cout<<endl;
      cout<<"------------------------------------------------------------------------\n";
    }
    else
    {
         cout<<"         please enter the value of height to get       \n";
         cout<<"           the Potential energy of object.\n";
         cin>>height;
         cout<<E.Calc(weight,D,height);
         cout<<endl;
         cout<<"------------------------------------------------------------------------\n";
    }
    
}



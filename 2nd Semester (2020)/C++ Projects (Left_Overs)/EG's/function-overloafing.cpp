#include<iostream>
#include<string>
using namespace std;
bool Display(int &age1, int &age2)
{ 
    bool a;
   if (age1<age2)
   {
       return (a=true);
   }
   else
   {
     return (a=false);
   }
}
void Display(string &name1, string &name2,bool &S)
{
     if (S==true)
   {
       cout<<name1<<" is younger then "<<name2<<endl;
       cout<<"-------------------------------\n"; 
   }
   else
    {
         cout<<name2<<" is younger then "<<name1<<endl;
         cout<<"-------------------------------\n"; 

    }
}



 
int main()
{
    cout<<"  +--------------------------------------------------------------------+ \n";
    cout<<"  |     Function Overloading is the 1st concept of section A           |\n";
    cout<<"  |     The concept says, We may have more then one functions          |\n";
    cout<<"  |     with same name and different parameters, This feature          |\n";
    cout<<"  |     is provided by C++ and not by C language.                      |\n";
    cout<<"  +--------------------------------------------------------------------+\n";
    
    cout<<"            *********************************************               \n";
    bool S;
    int age1,age2;
    string name1, name2;
  // inputs.
  cout<<"plz enter 1st name.\n";
  cin>>name1;
  cout<<"plz enter age of "<<name1<<endl;
  cin>>age1;
  cout<<"plz enter 2nd name.\n"; 
  cin>>name2;
  cout<<"plz enter age of "<<name2<<endl;
  cin>>age2;
  cout<<"-------------------------------\n";
  S= Display(age1,age2);
  Display(name1,name2,S);
 

}
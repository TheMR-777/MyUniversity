#include<iostream>
#include<string>
using namespace std;
class password
{ 
    
    string pass;
    public:
    void pass_check()
    {
    cin>>pass;
    if (pass.size()<8)
    {
        cout<<"Rule 1 is violated\n";
    }
    }
    int i=0,c=0;
    void pass_Uletter()
    {
        if(pass[i]>='A'&& pass[i]<='Z')
    {
        c++;
        i++;
    }
    if(c==0)
    {
        cout<<"Rule 2 is violated\n";
        
    }
    }
    void pass_Lletter()
    
    {
        if(pass[i]>='a'&& pass[i]<='z')
   {
    c++;
    i++;
   
   
      if(c==0)
      {
          cout<<"Rule 3 is violated\n";
      }

      }
    }
      void pass_int()
      {
      

      while((pass.size()>i))
      {
      if(pass[i]>='0' && pass[i]<='9')
      {
        
        c++;
      }
      i++;

      }
      if(c==0)
       cout<<"Rule 4 is violated\n";
      }
    
      
    
};
 
int main()
{
    cout<<"plz enter the password\n";
    cout<<"------------------------\n";
    cout<<"plz follow the rules while deciding the passworsd\n";
    cout<<"------------------------\n";
    cout<<" Rule 1:: password must be equal to or greater then 8 characters\n";
    cout<<"------------------------\n";
    cout<<"Rule 2:: password must include one upercase alphabet\n";
    cout<<"------------------------\n";
    cout<<"Rule 3:: password must contain one lowercase alphabet\n";
    cout<<"------------------------\n";
    cout<<"Rule 4:: password must contain an integer value\n";
     cout<<"------------------------\n";
    password p;

    cout<<"plz enter the password\n";
    p. pass_check();
    p.pass_Uletter();
    p.pass_Lletter();
    p.pass_int();

    

}
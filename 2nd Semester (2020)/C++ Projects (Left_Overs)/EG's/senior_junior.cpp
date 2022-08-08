#include<iostream>
#include<string>
using namespace std;
class senior_junior
{
  public:
  
   string name1 , name2, phoneNumber1 , phoneNumber2;
   int semesterNumber1,semesterNumber2;
  
      
     bool  sem_check(int &C1,int &C2) 
     {
         if(C1>C2)
         {
           return true;
         }
        else if(C1<C2)
        {
          return false;
        }
          
         
        
       }

   bool  phone_check(string  P, int u)
   {
       u=0;
      while (u<P.size())
      {
        u++;
      }

      if(u> 11|| u<11)
      {
        return false;
      }
      else 
      {
        return true;
      }

   }
 
     senior_junior(string &N1,string &N2, string &P1, string &P2,int C1, int C2)
      { name1=N1;
       name2=N2;
      
       semesterNumber1=C1;
       semesterNumber2=C2;
      
       phoneNumber1=P1;
       phoneNumber2=P2;
      
    }
     


};
 
       
 
    
int main()
{
    cout<<"----------------------------------------\n";
    cout<<"This program will tell you which student\n";
    cout<<"is senior and junior respectively.......\n";
    cout<<"----------------------------------------\n";
    bool b1,b2,b3;
    string N1,N2,P1,P2;
    int C1,C2,u=0;
    
    cout<<"please enter the name of 1st student: ";
    cin>> N1;
    cout<<"----------------------------------------\n";
    cout<<"please enter the name of 2nd student: ";
    cin>> N2;
    cout<<"----------------------------------------\n";
    cout<<"please enter the semester number of "<< N1 <<": ";
    cin>> C1;
    cout<<"----------------------------------------\n";
    cout<<"please enter the semester number of "<< N2 <<": ";;
    cin>> C2;
    cout<<"----------------------------------------\n";
    cout<<"please enter the phone number of  "<< N1 <<":";;
    cin>> P1;
    cout<<"----------------------------------------\n";
    cout<<"please enter the phone number of  "<< N2 <<": ";;
    cin>> P2;
    cout<<"----------------------------------------\n";
    senior_junior obj  ( N1, N2, P1, P2,C1, C2);
  
     
    cout<<"----------------------------------------\n";
     
   b1=   obj.sem_check(C1,C2);
   b2=   obj.phone_check(P1,u);
    b3=   obj.phone_check(P2,u);
  if(b1==true)
  {
      cout<<"the student named as "<<N1<<" is senior \n";
      cout<<"the student named as "<<N2<< "  is junior\n";
      
  }
  else if(b1==false)
  {
      
     cout<<"the student named as "<<N2<<" is senior \n";
      cout<<"the student named as "<<N1<< "  is junior\n";
  }
  else 
  {
    cout<<N1 << "  and  "<<N2 <<" both are in same semester  \n";
  }
  if (b2==false)
  {
      cout<< N1 <<"phone number is wrong \n";
  }
  else 
  {
    cout<<N1 <<" phone nummber is : "<<P1<<endl;;
  }
  if(b3==false)
  {
    cout<< N2 <<" phone number is wrong \n";
  }
  else {
     cout<<N2 <<" phone nummber is : "<<P2<<endl;
  }
  }
  
    

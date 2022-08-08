#include<iostream>
#include<vector>
#include <string>
using namespace std;
class STUDENT
{
     public:
     string name;
     string Roll;
    STUDENT()
    {
        cout<<"please tell your name.\n";
        cin>>name;
        cout<<"please input your roll number\n";
        cin>>Roll;
    }
    float sum;
    float Average(vector<float> &marks, bool op=1)
    { 
        
      for(int i=0; i<5; i++)
      { 
        sum=sum+marks[i] ;
      } 
      if(op==0) 
      {
         return sum/5;
      }
     
      else 
      {
         cout<<"you did not enter 0 so by default you got sum of your marks.\n";
          return sum;
      } 
    } 

};
int main()
{
    cout<<"+------------------------------------------------------------------------+\n";
    cout<<"      This the is Question 1 THE DEFAULT PARAMETER.                      |\n";
    cout<<"+------------------------------------------------------------------------+\n";
    cout<<"           *******************************                                \n";
    vector <float> marks;
    vector<string> subName{"oop","maths","English","DLD","electronics"};
    float temp,value;
    bool D;
    STUDENT S;
    cout<<"please enter your marks in eeach given subject.\n";
    for(int i=0; i<5; i++)
    {
        cout<<"please enter marks in "<<subName[i]<<" out of 50"<<endl;
        cin>>temp;
         marks.push_back(temp);
    }
   
    cout<<"please enter 0 to get the average marks.\n";
    cin>>D;
    if(D==0)
    {
       value= S.Average(marks,D);
       cout<<"The average marks are: "<<value;
    }
    else
    {
        value=S.Average(marks);
         cout<<"The total marks are: "<<value;
    }
    
   
    

}




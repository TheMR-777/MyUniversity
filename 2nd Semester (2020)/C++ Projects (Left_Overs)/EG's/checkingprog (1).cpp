#include<iostream>
#include<vector>
#include<string>
using namespace std;
// making class
class STUDENT
{ 
 
    
  public:

     vector<float> Percentage_calc  (vector<float> ObtMarksSum, int sum)
    {
       vector<float> percent;
       int i=0;
       for( i=0; i<ObtMarksSum.size(); i++)
         {
          percent[i]=(ObtMarksSum[i]/sum)*100;
          
         }
    return percent;
    }
       
       
   
 STUDENT(vector<float> &ObtMarksSum, int &Totalsum)
 {

   Percentage_calc  ( ObtMarksSum, Totalsum);
   
 }

};
// main function


int main()
{
       int size,x=0,Totalsum=0; float temp_f;
       
       int i=0,j=0;
       string temp;
       
    //inputs 
    cout<<"--------------------------------------------------\n";
    cout<<"please give some neccessary information as asked ..\n";  
    cout<<"---------------------------------------------------\n";
    cout<<"enter the strength of your class\n";
    cout<<"--------------------------------\n";
    cin>> size;
    vector<string> name(size) , subjName;
    vector<float> totalMarks,ObtMarksSum(size),percentage(size);

    cout<<"--------------------------------\n";
    cout<<"please give us information about the Subjects of Students.\n";
    cout<<"-----------------------------------------------------------\n";
    cout<<"please enter name of each subject\n";
    cout<<"------------------------------\n";
    cout<<"please enter [ f ] when you want to finish entering the values\n";
    cout<<"--------------------------------------------------------------\n";
    for(i=0; temp!="f"; i++)
    {
        cout<<"name of subject "<<1+i<<": ";
        cin>>temp;
        if(temp=="f")
        {
            break;
        }
        else
        {
            subjName.push_back(temp);
            cout<<endl;
            x++;
        }
        
        
    }
    vector<float> marks(x);
    subjName.shrink_to_fit();
     cout<<"------------------------------------------\n";
     for(i=0; i<x; i++)
   {
         cout<<"please enter total marks of "<<subjName[i]<<" ";
	       cin >> temp_f;
         totalMarks.push_back(temp_f);
        
         Totalsum=Totalsum+totalMarks[i];
        
         cout<<endl;
   }
   totalMarks.shrink_to_fit();
   
   cout<<"-------------------------------------\n";
  
     
 
    for (i=0; i<size; i++)
    {
      float sum=0;
        cout<<"please enter the name of student "<<i+1<<" ";
        cin>>name[i];
        for(j=0; j<x; j++)
        {
         cout<< "enter the "<< name[i] << "'s marks of "<< subjName[j]<<" ";
         cin>>marks[x];
         sum=sum+marks[x];
        }
        ObtMarksSum[i]=sum;
       
    }
     
     name.shrink_to_fit();

     
     cout<<"------------------------\n";
     STUDENT  S(ObtMarksSum,Totalsum);
    
     percentage  = S.Percentage_calc(ObtMarksSum,Totalsum);
    
    for(i=0; i<size; i++)
 {
   cout<<"the percentade is"<<percentage[i];
 }
   for (i=0; i<size; i++)
   {
        cout<<"name of student is "<< name[i];
        cout<<endl;
        cout<<"------------------------------\n";
        cout<<name[i]<< "'s total marks are"<< " are "<< ObtMarksSum[i]<<" out of "<<Totalsum;
        cout<<name[i]<< "'s percentage marks are " << percentage[i]; 
        cout<<endl;
        cout<<"--------------------------------\n";
       
 
     
   }

}
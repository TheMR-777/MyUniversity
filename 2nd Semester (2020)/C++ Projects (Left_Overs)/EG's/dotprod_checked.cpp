#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
int dot(vector <int> &v1 , vector <int> &v2)
{ 
  vector<int> product;
  int temp=0;
  int i,sum=0;
	for( i=0; i<v1.size(); i++)
	{
		temp=v1[i]*v2[i];
		product.push_back(temp);
		
	}
 
   	for(i=0; i<product.size(); i++)
	{
	  
		sum=sum+product[i];
	}
	
	return sum; 	
}
double magnitude(vector <int> V)
{
 
  int temp=0;
  int sum=0;
	for( int i=0; i<3; i++)
	{
		temp=V[i]*V[i];
	 
			sum=sum+ temp;
	}
 
 return sqrt(sum);
 
}
   
   
   int main()
   {
   	vector <int> v1(3);
	vector <int> v2(3);   	
   	int dotprod;
   	double length1,length2,dotMegRatio,angle;
   	cout<<"--------------------------------------------"<<endl;
   	cout<<"This program will calculate the dot-product and "<<endl;
   	cout<<"The magnitude and angle involved between two vectors"<<endl;
   	cout<<"--------------------------------------------"<<endl;
   	cout<<"please enter the elements of 1st vector\n";
   	cout<<"-----------------------------------------\n";
	for(int i=0; i<3; i++)   	   
	   {
	   	
	   	cout<<"enter 1st vector element# "<<i+1<<" ";
	   	cin>>v1[i];
	   	
	   }
	cout<<"The elements of 1st vector stored successfully\n";
	cout<<"-----------------------------------------\n";
    cout<<"please enter the elements of 2nd vector\n";
	cout<<"-----------------------------------------\n";
	 for(int i=0; i<3;  i++)   	   
	   { 
	   
	   	cout<<"enter 2nd vector element# "<<i+1<<" ";
	   	cin>>v2[i];
	    
	   } 
	    cout<<"The elements of 2nd vector stored successfully\n";
	  	cout<<"-----------------------------------------\n";
	   	cout<<"-----------------------------------------\n";
	   dotprod=dot( v1 , v2);
	  cout<<"the dot product of the two given vectors is::"<< dotprod<<endl;
	  cout<<"---------------------------------------------\n";
	   length1=magnitude( v1 );
	   length2=magnitude( v2 );
	   	cout<<"-----------------------------------------\n";
	  cout<<"the magnitude of 1st vectors is :: "<< length1<<endl;
	  cout<<"---------------------------------------------\n";
	  	cout<<"-----------------------------------------\n";
	  cout<<"the magnitude of 2nd vectors is :: "<< length2<<endl;
	  dotMegRatio=dotprod/(length1*length2);
	     
	  if(dotMegRatio>=-1&&dotMegRatio<=1 )
	  {
	   angle= acos(dotMegRatio);
	   	cout<<"-----------------------------------------\n";
	   		cout<<"-----------------------------------------\n";
	  cout<<"the angle between the two given vectors is :: " << angle<<endl;
	    }
	    else
	    {
	    	cout<<"maths error\n";
		}
	}



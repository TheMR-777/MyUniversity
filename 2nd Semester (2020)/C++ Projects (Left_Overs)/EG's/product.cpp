#include<iostream>
#include<vector>
using namespace std;


int product(vector<int> v1,  vector<int> v2 )
{
	int a[3],b[3];
	
	for(int i=0; i<3; i++)
	{
		 cout << a[i]+b[i];
	}
    
	return 0;
}

int main()
  
{
	int x;
 	char  a='i',b='j',c='k';    
    cout<<" please enter vector's i,j and k components\n ";
    vector<int> v1 (3);
	vector<int> v2 (3); 
	for(int i = 0 ; i<3; i++)
	{ 
		cout<<"1st vec element"<<i+1<<":\n";
 		cin>>v1[i];
 	}
	for(int i = 0 ; i<3; i++)
 
 	{ 
		cout<<"2nd vec element"<<i+1<<":\n";
 
	 	cin>>v2[i];
 	}
    product( v1, v2);

 }

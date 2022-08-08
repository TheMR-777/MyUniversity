#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	string stg;
	cout<<"please enter the given string\n";
	getline(cin,stg);
	cout<<"the given string is:"<<stg;
	cout<<"the size of given string is\n" <<stg.size()<<"\n";
	cout<<"the reverse of given string is:\n";
	for(int i=(stg.size()-1); i>0; i--)
	{
		cout<<stg[i];
	}
	cout<<"\n";		
}


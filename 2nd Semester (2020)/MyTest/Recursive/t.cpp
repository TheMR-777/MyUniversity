#include<iostream>
using namespace std;
int main()
{
    string str;
	cout<<"Enter string = ";
	cin>>str;
	cout<<"String size = "<<str.size()<<endl;
	cout<<endl;
	cout<<"Reverse in =";
	for(int i=(str.size()-1);i>=0;i--)
	{
		cout<<str[i];
	}
	cout<<endl;
}
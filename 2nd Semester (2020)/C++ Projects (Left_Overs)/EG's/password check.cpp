#include<iostream>
using namespace std;

void password()
{ int x;
cin>>x;
	if (x!=100)
	{
			cout<<"incorrect password please enter correct password\n";
	password();
	}
	else 
	{
		cout <<"given password is correct\n";
	}

}
int main()
{
 cout<<"please enter the password\n ";
 password();

}



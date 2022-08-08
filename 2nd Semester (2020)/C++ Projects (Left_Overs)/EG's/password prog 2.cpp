#include<iostream>
 using namespace std;
int main ()
{
 cout<<"please enter correct password\n";
int x;
cin>>x;
while(x!=100)
{
cout<<"you entered incorrect password\n";
cin>>x;
}
cout<<"you entered correct password\n";
}


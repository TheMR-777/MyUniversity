#include<iostream>
 using namespace std;
int main ()
{
    int x;
    cout<<"please enter correct password\n";
    cin>>x;
    for(int i=0; x!=100; i++ )
    {
        cout<<"you entered wrong value. please enter correct password\n";
        cin>>x;
    }
    cout<<"you entered correct password\n";
}

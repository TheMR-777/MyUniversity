#include <iostream>
using namespace std;
int main ()
{
    cout << "please enter correct password\n";
    int x;
    cin>>x;
    if (x==100)
    { 
        cout<<"you entered correct password\n";
    }
    else
    {
        do
        {
            cout<<"you entered incorrect password\n";
            cin>>x;
        }
    while(x!=100);
    }
}



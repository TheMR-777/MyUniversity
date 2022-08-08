#include <iostream>
using namespace std;

void Print ( int i )
{
    cout << "Int : " << i << endl;
}

void Print ( string s )
{
    cout << "String : " << s << endl;
}

void Print ( float f )
{
    cout << "Float : " << f << endl;
}

void Print ( double d )
{
    cout << "Double : " << d << endl;
}

int main()
{
    Print ("The_Overloaded_Function");
    Print (10);
    Print (1.2f);
    Print (2456.124553234);
}
#include <iostream>
using namespace std;

template<typename T>
void Printer(T something)
{
    cout << something << endl;
}


void double_f( int var_i , void(*func)(unsigned int) )
{
    unsigned int var_d = 1;
    for ( int i=var_i ; i > 0 ; i = i-2 )
    {
        var_d *= i;
        cout << i << " - ";
    }
    func(var_d);
}

int main()
{
    double_f(10 , Printer);
}
#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


void Print(int* a, int* b)
{
    Log("");
    Log("var : a = " << *a);
    Log("var : b = " << *b);
    Log("add : a = " << a);
    Log("add : b = " << b);
}

int main()
{
    // Intialization

        int* a = new int(10);
        int* b = new int(20);
        int* temp;

    
    // Showing the Values

        Print(a, b);


    // Shallow Copy

        temp = a;
        a = b;
        b = temp;

        Print(a, b);


    // Deep Copy

        *temp = *a;
        *a = *b;
        *b = *temp;

        Print(a, b);
}
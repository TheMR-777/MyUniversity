#include <iostream> 
#include <vector>
using namespace std;

int main()
{
    int a = 10;
    int& b = a;
    int* c = &a;

    a = 89;

    cout << "A : " << a << endl;
    cout << "B : " << b << endl;
    cout << "C : " << *c << endl;

    b = 77;

    cout << "A : " << a << endl;
    cout << "B : " << b << endl;
    cout << "C : " << *c << endl;
}
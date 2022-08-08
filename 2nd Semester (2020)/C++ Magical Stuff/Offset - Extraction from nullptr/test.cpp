#include <iostream>
using namespace std;

struct Vector {};

int main()
{
    int a = 10;
    int* p_a = &a;

    cout << p_a << endl;
    cout << &p_a << endl;
}
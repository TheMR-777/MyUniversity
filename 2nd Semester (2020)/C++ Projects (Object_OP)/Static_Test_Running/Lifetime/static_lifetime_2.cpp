#include <iostream> 
using namespace std;


int x_var = 0;

void show()
{
    x_var++;
    cout << x_var << endl;
}

int main()
{
    show();
    show();
    show();
    show();
    show();
}
#include <iostream> 
using namespace std;

void show()
{
    static int x_var = 0;
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
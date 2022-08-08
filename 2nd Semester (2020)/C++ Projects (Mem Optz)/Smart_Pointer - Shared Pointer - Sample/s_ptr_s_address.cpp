#include <iostream>
#include <memory>
using namespace std;

int main () 
{
    shared_ptr<int> s_ptr (new int (10));

    cout << " s_ptr: " << s_ptr << endl;
    cout << "*s_ptr: " << *s_ptr << endl;

    return 0;
}
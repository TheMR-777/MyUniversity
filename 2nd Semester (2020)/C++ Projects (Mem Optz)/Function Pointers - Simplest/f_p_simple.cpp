#include <iostream>
using namespace std;

void org_func()
{
    cout << "HelloWorld!" << endl;
}

int main()
{
    // Copying the Original Function by Reference
    // Using the C++ way of doing so

        auto copy_func = org_func;

        // Can also be written as:

        // auto copy_func = &org_func;

    // Copying the Original Function by Reference
    // Using the RAW C language way of doing so
    
        // void (*copy_func)() = org_func;

    // Calling our new function

        copy_func();
}
#include <iostream> 
using namespace std;

int main()
{
    // This program shows the most basic usage of * operator

        int x = 10;         // Original Variable
        int* ptr;           // Creating a Pointer of int data type
        ptr = &x;           // We stored the memory address of x using ampersand in ptr

    // In 2nd line, we created a Pointer to store the memory address of "x". We will discuss pointers in detail, later. 
    // In 3rd line, we stored the Memory Address of x into ptr, using & operator

    // Outputting the Results

        cout << "Original Variable (x) :             [ " << x << " ]" << endl;
        cout << "Address of (x) :                    [ " << &x << " ]" << endl;
        cout << endl;

        cout << "Value inside of the Pointer (ptr) : [ " << ptr << " ]" << endl;
        cout << "Dereferenced value of (ptr) :       [ " << *ptr << " ]" << endl;
        cout << "Address of the Pointer (ptr) :      [ " << &ptr << " ]" << endl; 
}
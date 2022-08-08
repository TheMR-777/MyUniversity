#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialization

        int x = 10;             // Declared a Variable
        void* ptr_v = &x;       // A void Pointer to that variable, which can't read and write properly
        int* ptr = &x;          // A Pointer to the x variable, with the Type defined

    // Proof

        cout << "The Original x Variable : [ " << x << " ]" << endl;
        cout << "Memory Address of x :     [ " << &x << " ]" << endl;
        cout << endl;

    // Dealing with void Pointer

        cout << "The address inside of the void pointer :           [ " << ptr_v << " ]" << endl;

        // Now the value inside of the VOID pointer can't be read normally
        // Becase our Compiler don't know how to READ that value. Is it an
        // integer, or double, or a string !?!?!? Compiler doesn't know.

        // We can Only read from there, if we specify that to be an Integer.
        // This method is called casting, which I will teach later on. I've
        // used Casting below

        cout << "The value at the address inside the void pointer : [ " << *( (int*) ptr_v ) << " ]" << endl;

        // I first told the compiler, that the Pointer is "int" pointer (int*).
        // Compiler agreed. then I told it, that it should dereference that
        // resultant pointer. If it seems difficult, just forget the void ptr,
        // and move to the next section below.

        cout << "The Address OF the VOID pointer :                  [ " << &ptr_v << " ]" << endl;
        cout << endl;

    // Dealing with the General C Style RAW Pointer

        cout << "Address inside the INT pointer : [ " << ptr << " ]" << endl;
        cout << "Value at that address          : [ " << *ptr << " ]" << endl;
        cout << "Address of this pointer        : [ " << &ptr << " ]" << endl;
}
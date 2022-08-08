#include <iostream> 
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> u_ptr_1 = make_unique<int>();
    
    {
        unique_ptr<int> u_ptr_2 = make_unique<int> (10);
        cout << " u_ptr_2 - " << u_ptr_2.get() << endl;         // Address pointed by the Pointer wrapped in the Object
        cout << "*u_ptr_2 - " << *u_ptr_2 << endl;              // Value being pointed by the object of Unique Pointer (10)
        cout << "&u_ptr_2 - " << &u_ptr_2 << endl;              // Address of Unique Pointer on Stack
        cout << endl;

        cout << ">---[Transfered_Ownership]---<" << endl;

        cout << endl;
        u_ptr_1 = move(u_ptr_2);                                // Transferring Ownership
    }

    cout << " u_ptr_1 - " << u_ptr_1.get() << endl;
    cout << "*u_ptr_1 - " << *u_ptr_1 << endl;
    cout << "&u_ptr_1 - " << &u_ptr_1 << endl;
}




/*

Tips :-
=======

 - Unique Pointer is an Object, which contains the Normal Pointer along with additional functionalities
   containing a default delete option as well.
 - The Unique Pointer is always created on the stack, but the value which is being pointed by the
   unique pointer is always created on HEAP Memory, if make_unique function is used.

 - To Transfer ownership of the unique pointer to the other unique poniter, we use move function
        unique_pointer_1 = move( unique_pointer_2 );
 - To empty the unique pointer in the standard pointer, we use .release() function of unique_ptr :
        standard_pointer = unique_pointer.release();
 - To copy the Unique pointer in the standard pointer, we use the .get() function, which returns the
   address of the value pointed by that unique pointer,
        standard_pointer = unique_pointer.get();

 - Dereferncing the Unique Pointer results the Value Pointed by the Unique Pointer
 - Referncing the Unique Pointer results the address of that unique pointer on the stack
 - Using the .get() function returns the Address of the value pointed by the Unique Pointer.

 - Difference of .get() and .release() function :

    - .get() function returns the address of the value being pointed. Just this
    - .release() function returns the address of the value being pointed, but
      also empties the unique pointer.

*/
#include <iostream>
using namespace std;

struct Vector
{
	float x = 10, y = 100, z = 1000;
};


int main()
{
	// For MinGW Compiler :

		cout << (int*) &((Vector*)nullptr) -> z << endl;
		cout << (intptr_t) &((Vector*) nullptr) -> z << endl;

	// For Visual Studio Compiler :

		// cout << (int)&((Vector*)nullptr)->z;
}











// First, we make a Null_Pointer
// Then, we cast it into Vector Type. To change it's properties. It's just like , we put the soul of Vector in the Null Pointer.
// Now, We have to ask the Memory Address from the null pointer of that variable, pointed by ->

// The Null Pointer says, he knows nothing about it. That's y, returns error. But, the Vector class knows! (I mean, it's soul knows)
// We have to ask from the soul of the Pointer, to which position, will it put the variable, pointed by ->
// So, we use &, to get the address of that pointer. Yes, pointer also has address of it's own.
// That address is surely the Soul, we put it that pointer, and Yes! it knows where to put the variable in memory block.

// We then get the position, or u may say, the offset.
// To show that on screen, we cast it into int. (It's optional)
// In VS, it will return a Magnitude of offset.
// In MinGW, or anyother Compiler, it will return offset in Memory's Language. Which can't be dereferenced, for unknown reason.


// Description by a Commenteer :
/*

- You cast a 0 into a Vector3*. Now, since a pointer is a variable that stores a memory address, it translates that into memory adress 00000000, so that's the adress it's now pointing to. 
- Now, when you try to use the -> operator to get the value of one of the variables of the object that the pointer is supposed to be pointing to,... 
- You get some kind of an error since there's actully no object being pointed to and therefore there's no value at the memory address.

- However, even though there's no underlying object, a pointer to a class/struct still knows how an object of that class/struct is supposed to be structured in memory. 
- So when you use the & to get the memory adress the variable is supposed to be stored at, instead of trying to get the data stored there, it actually returns a valid value .

- Since the only pieces of data this particular Vector3 object needs to store in memory are member variables X, Y and Z, 
- The first variable, X is stored at the address the pointer is pointing to , 00000000. 
- Since all 3 data members are floats, and a float is of 4 bytes, that means that X takes up memory adresses 00000000 , 00000001 , 00000002 and 00000003. 
- Then 00000004 through 00000007 is Y and 00000008 through 00000011 is Z.  
- But when you're returning the address of a variable, you only get the address where the 1st byte is stored and the rest of it is stored in the following adresses. 
- And then you just cast it into an int to convert the address value from hexadecimal to decimal and send to cout.
*/
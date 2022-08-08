#include <iostream>
using namespace std;


// Passing

void function1( string &passed )   
{   
   // Parent function's variable abc is now aliased as passed and available for general usage.
   cout << passed << " is from parent function.";   
}   
void function2( string &passed )   
{   
    // Parent function's variable abc is now aliased as passed and available for general usage.
   cout << passed << " is from parent function.";   
} 
void parentFunction( )
{
    string abc;  
    cin >> abc;
    function1( abc );  
    function2( abc );  
}

// Main

int main()
{
	parentFunction();
}

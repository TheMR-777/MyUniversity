/*

- Description of Conditional Statements

1. The statement "if" can be used independantly, without the
   else statement

2. IF the Arguments passed in the "if" statement returns "true",
   it'll execute the statement under its scope.

3. IF the Arguments passed in the "if" statement returns "false",
   it'll execute the statement under the "else" scope.

4. Check the code below for better undersatanding.
   Uncomment the Commented line to see the Different results

*/



// Initializing Condition

    let c : boolean = true;
    // let c : boolean = false;

// Using Condition in If-else to check "c"

    if(c)
    {
        console.log("Condition is True, Varification : " + c);
    }
    else
    {
        console.log("Condition is False, Varification : " + c);
    }
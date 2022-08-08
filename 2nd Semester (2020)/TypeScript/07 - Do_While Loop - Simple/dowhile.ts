/*

- Description of do-while loop

1. Do-while loop is mostly used in the Main Menu screens
2. Do-while loop has a slightly different structure as
   compared to "while" loop.
3. In Do-while loop, the condition is checked, after the
   execution of code inside its scope.
4. Structure of do-while loop:

    do
    {
        // Any Code
    } 
    while( CONDITION );

5. This loop is also Scope based

*/





let n:number = 0;

do
{
    n += 1;
} while ( n < 100 );

console.log(n);
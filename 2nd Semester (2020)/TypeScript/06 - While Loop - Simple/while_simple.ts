/*

- Description of "while" loop

1. "while" loop is widely used to deal with the data, whose
   ending point is unknown. For Example, in a Game, the
   rendering frames are always continously rendered inside
   of the "while" loop.

2. In while loop, the condition is checked, before the execution
   of code under its scope

3. Structure of "while" loop :

    while( CONDITION )
    {
        // Any Code here
    }

4. "while" loop also has its own Scope

*/





let n1:number = 0;

while( n1 < 100 )
{
    n1 += 1;
}

console.log(n1);
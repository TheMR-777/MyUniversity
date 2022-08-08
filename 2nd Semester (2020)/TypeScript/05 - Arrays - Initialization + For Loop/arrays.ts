/*

- Description of Arrays

1. Arrays are used, if we want to store a certain sequence of Data, under
   the same Category.

2. Check the following code, to understand it's Initializing techniques,
   and Output methods


==========================================================================

- Description of "for" loop

1. "for" loop is mostly used to deal with Arrays, or Quantitative sequence
   of data. Check the below code for better understanding

2. The structure of the "for" loop is following :

    for( IDENTATION ; CONDITION ; UPDATION )
    {
        // Any Code to be executed
    }

3. "for" loop has its own scope

*/








// Initialization of String Arrays in TS

    let ar1: string[] = [ "Numbers", "Strings", "Booleans", "NULL" ];

    console.log("\n String Array :\n");
    for( let a = 0; a < ar1.length; a++ )
    {
        console.log(ar1[a]);
    }

// Initialization of Number Arrays in TS

    let ar2: number[] = [ 17, 9, 78, 1, 9, 0, 4, 71, 8, 27, 5, 11 ];

    console.log("\n Number Array :\n");
    for( let a = 0; a < ar2.length; a++ )
    {
        console.log(ar2[a]);
    }

// Initialization of Boolean Arrays in TS (Optional)

    let ar3: boolean[] = [ true, true, true, false, false, false ];

    console.log("\n Boolean Array :\n");
    for( let a = 0; a < ar3.length; a++ )
    {
        console.log(ar3[a]);
    }
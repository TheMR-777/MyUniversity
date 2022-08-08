/*

- Description of Error Management

1. Errors in TypeScript can be managed by using try, throw and catch
   system of management

2. The "try" executes the code of its scope, and we use the throw
   statement, if something we want to show as error

3. The "catch" catches the statement thrown by "throw" and manages the
   error as the code inside of its own scope.

4. Check the following example to check the working of this system
   Uncomment the Code under the section of : The Invalid Code, to
   understand the working of "throw" and "catch"

*/






try
{
    // The Valid Code

        let n1: number = 10 + 20;
        console.log("The SUM of 10 and 20 = " + n1)

    // The Invalid Code

        // let n2: number = 10 / 0;
        // console.log("10 devided by Zero : " + n2);
        // throw n2;
}
catch(err)
{
    console.log("Invalid Statement Executed! - " + err);
}
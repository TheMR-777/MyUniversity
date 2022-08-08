#include <iostream>
using namespace std;

void Cap_B( string name )
{
    for ( int i=0 ; i < name.size() ; i++ )
    {
        if ( name[i] >= 'a' && name[i] <= 'z' )
        {
            name[i] -= 32;
        }
    }

    cout << "[ B ]  Capitalized String : " << name << endl;
}

void Cap_L_1( string name )
{
    for ( int i=0 ; i < name.size() ; i++ )
    {
        name[i] = ( name[i] * !( name[i] >= 'a' && name[i] <= 'z' ) ) + ( (name[i] - 32) * ( name[i] >= 'a' && name[i] <= 'z' ) );
    }

    cout << "[ L1 ] Capitalized String : " << name << endl;
}

void Cap_L_2( string name )
{
    for ( int i=0 ; i < name.size() ; i++ )
    {
        name[i] = name[i] - 32 * ( name[i] >= 'a' && name[i] <= 'z' );
    }

    cout << "[ L2 ] Capitalized String : " << name << endl;
}



int main()
{
    // Initialization

        string name = "Wow, It is working!";

    // Calling the Branched Code

        Cap_B(name);

    // Calling the 1st Branchless Code

        Cap_L_1(name);

    // Calling the 2nd Branchless Code

        Cap_L_2(name);
}



// Checking the ASCII

// for ( char c = 'A' ; c <= 'Z' ; c++ )
// {
//     cout << "Char : " << c << " - ASCII : " << (int)c << endl;
// }
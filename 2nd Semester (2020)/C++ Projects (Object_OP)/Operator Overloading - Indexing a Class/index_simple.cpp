#include <iostream>
using namespace std;

struct Vector
{

    // Public Variables

        int x , y , z;

    // Constructor

        Vector( int x , int y , int z )
            : x(x), y(y), z(z) {}

    // Operator[] overload

        int & operator[] (unsigned int i)
        {
            return *(int*)( (char*)this + i*sizeof(int) );
        }
};

int main()
{
    // Initialization

        Vector V ( 4 , 6 , 7 );

    // Output

        for ( int i=0 ; i < 3 ; i++ )
        {
            cout << "Element : " << V[i] << endl;
        }
}
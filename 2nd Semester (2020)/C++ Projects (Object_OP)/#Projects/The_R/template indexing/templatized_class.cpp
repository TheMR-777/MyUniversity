#include <iostream>
using namespace std;

template<typename T>
struct Vector
{
    T x, y, z;

    // Methods

        Vector ( T x , T y , T z )
            : x(x), y(y), z(z)  {}
};

namespace The_R
{
    template<typename ANY>
    ANY & operator[] ( int i )
}

int main()
{
    Vector<int> ( 3, 3, 7 );
    Vector<string> ( "MR" , "_777" , "19" );
}
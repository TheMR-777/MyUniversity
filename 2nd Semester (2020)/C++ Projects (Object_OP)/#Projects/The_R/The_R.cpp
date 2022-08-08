#include <iostream>
using namespace std;

template<typename T>
class Vector
{
    T x, y, z;

    public:

        Vector( T x , T y , T z )
            : x(x) , y(y) , z(z) {}

        T & operator[] (unsigned int i)
        {
            return *(T*)( (char*)this + i*sizeof(T) );
        }
};

int main()
{
    Vector<string> V ( "Harris" , "Ali TP" , "MR" );

    for ( int i=0 ; i < 3 ; i++ )
    {
        cout << "Element #" << i+1 << " - [ " << V[i] << " ]" << endl;
    }
}
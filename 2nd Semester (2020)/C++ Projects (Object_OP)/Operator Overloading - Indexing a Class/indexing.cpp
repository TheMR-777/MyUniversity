#include <iostream>
using namespace std;

template<class T>
class Vector
{
    T x, y, z;

    public:

        Vector( T x , T y , T z )
            : x(x) , y(y) , z(z) {}

        T & operator[] (unsigned int i)
        {
            return *(int*)( (char*)this + i*sizeof(T) );
        }
};

int main()
{
    Vector<int> V ( 8 , 3 , 6 );

    for ( int i=0 ; i < 3 ; i++ )
    {
        cout << "Element #" << i+1 << " - [ " << V[i] << " ]" << endl;
    }
}
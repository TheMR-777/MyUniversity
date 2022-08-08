#include <iostream>
using namespace std;

template<class T>
class Vector
{
    T x , y , z;

    public:

        Vector ( T x , T y , T z )
            : x(x) , y(y) , z(z) {}

        T& operator[] (unsigned short &i)
        {
            return ( *(int*)((char*)this + i*sizeof(T)) );
        }

        size()
        {
            return ( sizeof(this) / sizeof(T) + 1 );
        }
};



int main()
{
    Vector<int> V ( 8 , 45 , 2 );
    
    for ( unsigned short i=0; i < V.size(); i++ )
    {
        cout << "Elemtnt #" << i+1 << " - [ " << V[i] << " ]" << endl;
    }
}
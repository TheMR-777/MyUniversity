#include <iostream>
using namespace std;

template<class T>
class Vector
{
    T x , y , z;

    public:

        Vector( T x , T y , T z )
            : x(x) , y(y) , z(z) {}

        unsigned short size()
        {
            return ( sizeof(this) / sizeof(T) ) + 1;
        }

};

int main()
{
    Vector<int>* VA_Vector = new Vector<int> (2 , 4 , 3);
    int* iA_Vector = (int*) VA_Vector;

    for ( int i=0 ; i < VA_Vector->size() ; i++ )
    {
        cout << "Element #" << i+1 << " - [ " << *(int*)((char*)VA_Vector + i*sizeof(int)) << " ]" << endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;

class Vector
{
    int x, y, z;

    public:

        Vector ( int x , int y , int z )
            : x(x), y(y), z(z)  {}

        void Print()
        {
            cout << "[x] - " << x << endl;
            cout << "[y] - " << y << endl;
            cout << "[z] - " << z << endl;
        }
};

class ScopedPtr
{
    Vector * m_V;

    public:

        ScopedPtr( Vector* V )
            : m_V(V)  {}

        Vector* GetPtr()
        {
            return m_V;
        }

        Vector* operator-> ()
        {
            return m_V;
        }

        Vector* operator-> () const
        {
            return m_V;
        }

        ~ScopedPtr()
        {
            delete m_V;
        }
};

int main()
{
    const ScopedPtr p_V = new Vector ( 1,2,3 );
    p_V->Print();
}
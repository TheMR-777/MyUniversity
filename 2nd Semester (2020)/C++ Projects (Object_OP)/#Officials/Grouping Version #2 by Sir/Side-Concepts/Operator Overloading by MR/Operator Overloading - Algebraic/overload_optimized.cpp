#include <iostream>
using namespace std;

class Vector
{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;

    public:

    // Constructor

        Vector(float x = 0.0 , float y = 0.0 , float z = 0.0)
            : x(x) , y(y) , z(z) {}
    
    // Overloaders

        Vector operator+ ( const Vector &V )
        {
            return Vector( x + V.x , y + V.y , z + V.z );
        }

        Vector operator- ( const Vector &V )
        {
            return Vector( x - V.x , y - V.y , z - V.z );
        }

        Vector operator* ( const Vector &V )
        {
            return Vector( x * V.x , y * V.y , z * V.z );
        }


    // Printer

        void Print()
        {
            cout << " [ x ] - Coordinate : " << x << endl;
            cout << " [ y ] - Coordinate : " << y << endl;
            cout << " [ z ] - Coordinate : " << z << endl;
            cout << endl;
        }
};


int main()
{
    // Initialization

        Vector A (2,6,4);
        Vector B (8,4,6);
        system("cls");

    // Sum

        cout << "The Sum of 2 Vectors is :" << endl;
        (A + B).Print();

    // Difference

        cout << "The Difference of 2 Vectors is :" << endl;
        (A - B).Print();

    // Product

        cout << "The Product of 2 Vectors is :" << endl;
        (A * B).Print();
}
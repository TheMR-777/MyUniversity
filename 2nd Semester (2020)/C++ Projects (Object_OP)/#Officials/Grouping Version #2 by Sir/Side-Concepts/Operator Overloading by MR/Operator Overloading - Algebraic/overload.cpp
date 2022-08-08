#include <iostream>
using namespace std;

class Vector
{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;

    public:

    // Overloaders

        Vector operator+ ( Vector V )
        {
            Vector T;
            T.x = x + V.x;
            T.y = y + V.y;
            T.z = z + V.z;

            return T;
        }

        Vector operator- ( Vector V )
        {
            Vector T;
            T.x = x - V.x;
            T.y = y - V.y;
            T.z = z - V.z;

            return T;
        }

        Vector operator* ( Vector V )
        {
            Vector T;
            T.x = x * V.x;
            T.y = y * V.y;
            T.z = z * V.z;

            return T;
        }

    // Constructor

        Vector(float x = 0.0 , float y = 0.0 , float z = 0.0)
        {
            this->x = x;
            this->y = y;
            this->z = z;
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
        Vector Result;
        system("cls");

    // Sum

        cout << "The Sum of 2 Vectors is :" << endl;
        Result = A + B;
        Result.Print();

    // Difference

        cout << "The Difference of 2 Vectors is :" << endl;
        Result = A - B;
        Result.Print();

    // Product

        cout << "The Product of 2 Vectors is :" << endl;
        Result = A * B;
        Result.Print();
}
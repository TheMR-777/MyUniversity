#include <iostream>
using namespace std;

class Vector
{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;

    public:

    // Constructor

        Vector(float&& x = 0.0 , float&& y = 0.0 , float&& z = 0.0)
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

        friend ostream& operator<< (ostream &output, Vector &V);
        friend istream& operator>> (istream &input , Vector &V);


    // Printer

        void Print()
        {
            cout << " [ x ] - Coordinate : " << x << endl;
            cout << " [ y ] - Coordinate : " << y << endl;
            cout << " [ z ] - Coordinate : " << z << endl;
            cout << endl;
        }
};


ostream& operator<< (ostream &output, Vector &V)
{
    output << " [ x ] - Coordinate : " << V.x << '\n';
    output << " [ y ] - Coordinate : " << V.y << '\n';
    output << " [ z ] - Coordinate : " << V.z << '\n';

    return output;
}

istream& operator>> (istream &input , Vector &V)
{
    cin >> V.x >> V.y >> V.z;
    return input;
}


int main()
{
    // Initialization

        Vector A (2,6,4);
        Vector B (8,4,6);
        Vector R;
        system("cls");

    // Sum

        cout << "The Sum of 2 Vectors is :" << endl;
        R = A+B;
        cout << R << endl;
        // (A + B).Print();

    // Difference

        cout << "The Difference of 2 Vectors is :" << endl;
        R = A-B;
        cout << R << endl;

    // Product

        cout << "The Product of 2 Vectors is :" << endl;
        R = A*B;
        cout << R << endl;
}
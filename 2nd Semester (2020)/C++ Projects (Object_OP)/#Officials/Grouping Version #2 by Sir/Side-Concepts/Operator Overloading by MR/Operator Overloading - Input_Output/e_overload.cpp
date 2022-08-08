#include <iostream> 
#include <vector>
using namespace std;

class Vector
{
    public :

        float x = 0.0;
        float y = 0.0;
        float z = 0.0;

};



ostream &operator<< ( ostream &Output , Vector &V )
{
    Output << "[ x ] : " << V.x << "\n[ y ] : " << V.y << "\n[ z ] : " << V.z;
    return Output;
}

istream &operator>> ( istream &Input , Vector &V )
{
    Input >> V.x >> V.y >> V.z;
    return Input;
}



int main()
{
    // Initialization

        Vector A;

    // Display Screen

        cout << "Enter Vector's [ i, j, k ] Coordinates seperated by single Space" << endl;
        cout << "|" << endl;
        cout << "+--> ";

    // Input

        cin >> A;

    // Output

        cout << endl;
        cout << A << endl;
}
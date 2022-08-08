#include <iostream>
using namespace std;


struct Vector2
{
    float i , j;

    void Print()
    {
        cout << "[ i ] - " << i << endl;
        cout << "[ j ] - " << j << endl;
    }
};

struct Vector4
{
    union
    {
        struct
        {
            float i , j , i1 , j1;
        };
        
        struct
        {
            Vector2 A , B;
        };
    };

    void Print()
    {
        A.Print();
        B.Print();
    }
};


int main()
{
    // Using the Vector2 as Normal

        cout << "\nResults of Vector2" << endl;
        cout << "----------------------" << endl;
        Vector2 V2 = { 2.6 , 9.4};
        V2.Print();

    // Using the Vector4 - As Vector4

        cout << "\nResults of Vector2 #1" << endl;
        cout << "----------------------" << endl;
        Vector4 V4 = { 5.9 , 3.5 , 8.1 , 7.7 };
        V4.Print();

    // Using the Vector4 - As Vector2

        cout << "\nResults of Vector2 #2" << endl;
        cout << "----------------------" << endl;
        Vector4 V4_2 = { 4.4 , 5.1 , 3.9 , 7.3 };
        V4_2.A.Print();
        V4_2.B.Print();
}
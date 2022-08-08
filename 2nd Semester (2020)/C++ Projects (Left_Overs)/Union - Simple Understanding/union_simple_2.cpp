#include <iostream>
using namespace std;

union U
{
    float x;
    float y;
    float z;
};

int main()
{
    system("cls"); cout << endl;

    // Initializing the Union

        U My_Union;

    // Setting variable

        My_Union.x = 10;        

    // Varification

        cout << "Value : " << My_Union.x << " - Address : " << & My_Union.x << endl;
        cout << "Value : " << My_Union.y << " - Address : " << & My_Union.y << endl;
        cout << "Value : " << My_Union.z << " - Address : " << & My_Union.z << endl;
        cout << endl;
        cout << "Address of the Union itself : " << &My_Union << endl;

    // Finalize

        cout << endl;
        cin.get();
}
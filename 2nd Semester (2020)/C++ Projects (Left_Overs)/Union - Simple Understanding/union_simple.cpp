#include <iostream>
using namespace std;

int main()
{
        system("cls"); cout << endl;

    // Initializing the Union

        union
        {
            float x;
            float y;
            float z;
        };

    // Setting variable
    
        x = 10;

    // Check

        cout << "Value : " << x << " - Address : " << &x << endl;
        cout << "Value : " << y << " - Address : " << &y << endl;
        cout << "Value : " << z << " - Address : " << &z << endl;

    // Finalize

        cout << endl;
        cin.get();
}
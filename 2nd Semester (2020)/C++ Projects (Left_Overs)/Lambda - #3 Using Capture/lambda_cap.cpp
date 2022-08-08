#include <iostream>
using namespace std;

int main()
{
    // Initializing Variables

        int a = 10;
        int b = 40;

    // Initializing Lambda

        auto Lambda = [&](int x , int y)
        {
            return a + b + x + y;
        };

    // Returning Values

        cout << Lambda( 21 , 89 );
}
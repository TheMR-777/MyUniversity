#include <iostream>
using namespace std;

// Abstract Base class

class Base
{
    protected:

        float x, y;
        Base() = default;
};

// Concrete Class

class Vector2 : protected Base
{
    public:

        Vector2(float&& x, float&& y)
        {
            this->x = x; this->y = y;
        }

        float Sum()
        {
            return x + y;
        }
};

int main()
{
	Vector2 V(5.4, 8.9);
	cout << V.Sum();
}
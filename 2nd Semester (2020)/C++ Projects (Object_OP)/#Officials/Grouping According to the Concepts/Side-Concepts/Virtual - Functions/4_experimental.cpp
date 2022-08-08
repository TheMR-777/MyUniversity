#include <iostream>
using namespace std;


class Base
{
    public:

    Base()
    {
        cout << "| Base Created!" << endl;
    }

    void Get()
    {
        cout << "| I am Base Class" << endl;
    }

    ~Base()
    {
        cout << "| Base Destructed!" << endl;
    }
};

class Derived : public Base
{
    public:

    Derived()
    {
        cout << "| Derived Created!" << endl;
    }

    void Get()
    {
        cout << "| I am Derived Class" << endl;
    }

    ~Derived()
    {
        cout << "| Derived Destructed!" << endl;
    }
};



int main()
{
    // Initialization

        cout << "-----------------------------------------------" << endl;
        Derived D;

    // Showing Results

        cout << "-----------------------------------------------" << endl;
        D.Get();

    // Let's tweak something (Using Polymorphism)

        cout << "-----------------------------------------------" << endl;
        ((Base)D).Get();
        cout << "-----------------------------------------------" << endl;
}
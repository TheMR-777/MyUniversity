#include <iostream>
using namespace std;


class BASE
{

    public:

    void Get()
    {
        cout << "| Base Class called!" << endl;
    }
};

class DER : public BASE
{
    
    public:

    void Get()
    {
        cout << "| Derived Class called!" << endl;
    }
};


// The Function below can print the BASE class, as well as from the Classes Inherited by it

void Print( BASE& B )
{
    B.Get();
}


int main()
{
    // Initialization

        BASE B;
        DER D;

    // Checking the working

        cout << "Check" << endl;

        B.Get();
        D.Get();

        cout << endl;

    // Casting Derived class into another BASE class

        cout << "Casting" << endl;

        BASE t_B = (BASE)D;
        t_B.Get();

        cout << endl;

    // Casting Base class into a Derived class (will never work)

        // DER t_D = (DER)B;
        // t_D.Get();

    // Calling BASE Function via different Objects( which work )

        cout << "BASE Function Calling" << endl;

        Print(B);
        Print(D);
        Print(t_B);

        cout << endl;
}
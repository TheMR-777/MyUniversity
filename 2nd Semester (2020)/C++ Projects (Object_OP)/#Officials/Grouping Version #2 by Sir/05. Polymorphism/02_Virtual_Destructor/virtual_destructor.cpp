#include <iostream>
using namespace std;


class Base
{
    public:

        Base()
        {
            cout << "Base Constructor" << endl;
        }

        virtual
        ~Base()
        {
            cout << "Base Destructor" << endl;
        }
};

class Derived : public Base
{
    public:

        Derived()
        {
            cout << "Derived Constructor" << endl;
        }

        ~Derived()
        {
            cout << "Derived Destructor" << endl;
        }
};


int main()
{
    system("cls"); cout << endl;
    cout << "-----------------------------------------" << endl;

    // Initializing BASE Only

        Base* Base_Test = new Base();
        cout << endl;
        delete Base_Test;

    // Initializing DERIVED Only

        cout << "-----------------------------------------" << endl;
        Derived* Derived_Test = new Derived();
        cout << endl;
        delete Derived_Test;

    // Initializing DERIVED as a BASE

        cout << "-----------------------------------------" << endl;
        Base* Derived_Based = new Derived();
        cout << endl;
        delete Derived_Based;

    // Finalizing

        cout << "-----------------------------------------" << endl;
        cout << endl;
}
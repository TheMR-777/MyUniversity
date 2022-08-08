#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


class Base1
{
    public:

        virtual
        void Get_info()
        {
            Log("> This is Base Class");
        }
};

class Base2
{
    public:

        virtual
        void Get_info() = 0;
};

class Derived : public Base1, public Base2
{
    public:

        void Get_info() override
        {
            Log("> This is Derived Class");
        }
};



int main()
{

    // Initializing Derived Class
    // --------------------------

        Derived D;


    // Virtual Function of Base #1
    // ---------------------------

        Log("");
        D.Get_info();
        (*(Base1*)(&D)).Get_info();

    
    // Pure Virtual Function of Base #2
    // --------------------------------

        Log("");
        D.Get_info();
        (*(Base2*)(&D)).Get_info();

}
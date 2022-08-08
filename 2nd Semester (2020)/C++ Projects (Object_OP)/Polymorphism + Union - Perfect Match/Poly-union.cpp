#include <iostream>
using namespace std;
#define LOG(x) cout << x << endl

class Base
{
    public:

        Base()
        {
            LOG("| Base Constructed!");
        }

        void Check()
        {
            LOG("| This is Base Class");
        }

        ~Base()
        {
            LOG("| Base Destructed!");
        }
};

class Derived : public Base
{
    public:

        Derived()
        {
            LOG("| Derived Constructed!");
        }

        void Check()
        {
            LOG("| This is Derived Class");
        }

        ~Derived()
        {
            LOG("| Derived Destructed!");
        }
};



int main()
{
    
    Base B; Derived D;

}
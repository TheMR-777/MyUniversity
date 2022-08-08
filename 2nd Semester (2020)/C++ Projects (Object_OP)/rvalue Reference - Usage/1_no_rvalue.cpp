#include <iostream>
using namespace std;

class Target
{
    int x;
    public:

        Target(const int& i)
        {
            this->x = i;
        }

        void operator= (const Target& T)
        {
            this->x = T.x;
            cout << "Target Copied!" << endl;
        }

        void Print()
        {
            cout << "[ x ] = " << x << endl;
        }
};

int main()
{
    Target A(3), B(6);
    A = B;
    A.Print(); B.Print();
}
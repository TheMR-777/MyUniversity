#include <iostream> 
using namespace std;

struct Pair
{
    int const_x = 10;
    mutable int muted_x = 70;
};

int main()
{
    // Initializing a Constant Pair
    
        const Pair entity;

    // Differentiating Const. & Mutable

        // Mutable Variable can be modified, regaurdless of the Permissions
        entity.muted_x = 80;

        // Constant Variables can't be modified
        // entity.const_x = 70;
}
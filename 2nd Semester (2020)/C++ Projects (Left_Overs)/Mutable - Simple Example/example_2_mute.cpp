#include <iostream> 
using namespace std;

struct Pair
{
    int x = 10;
    mutable int muted_x = 50;
};


void changer( const Pair &entity )
{
    entity.muted_x = 100;
}


int main()
{
    Pair entity;

    changer(entity);
}
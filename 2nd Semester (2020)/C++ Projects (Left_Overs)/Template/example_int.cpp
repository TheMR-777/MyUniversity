#include <iostream>
#include <vector>
using namespace std;

template<typename T>

T SUM( T X , T Y )
{
    return (X+Y);
}




int main()
{
    int iX, iY;

    iX = 5.0;
    iY = 10;

    cout << SUM(iX , iY);
}
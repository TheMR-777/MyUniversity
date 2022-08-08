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
    string sX, sY;

    sX = "Wow ";
    sY = "Amazing!";

    cout << SUM(sX , sY);
}
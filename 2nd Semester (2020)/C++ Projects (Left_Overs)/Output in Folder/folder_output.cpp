#include <iostream>
#include <sstream>
#include <string>
#include <direct.h> // for _mkdir
using namespace std;

int main()
{
    int counter = 0;
    while(counter < 10)
    {
        ostringstream oss;
        oss << "ABCDEF " << counter;
        _mkdir(oss.str().c_str());
        counter++;
    }
    return 0; // main returns 0 even if it's not explicit,
              // so you might as well make this clear!
}
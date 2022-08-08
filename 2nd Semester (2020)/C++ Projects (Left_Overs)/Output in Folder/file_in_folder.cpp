#include <iostream>
#include <fstream>
#include <direct.h>
using namespace std;

int main()
{
    _mkdir("Test");

    ofstream FILE ("Test\\test.txt");
}
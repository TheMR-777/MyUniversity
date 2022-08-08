#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

enum colour { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

struct setcolour
{
   colour _c;
   HANDLE _console_handle;


       setcolour(colour c, HANDLE console_handle)
           : _c(c), _console_handle(0)
       { 
           _console_handle = console_handle;
       }
};

// We could use a template here, making it more generic. Wide streams won't
// work with this version.
basic_ostream<char> &operator<<(basic_ostream<char> &s, const setcolour &ref)
{
    SetConsoleTextAttribute(ref._console_handle, ref._c);
    return s;
}

int main(int argc, char *argv[])
{
    HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "standard text" << setcolour(RED, chandle) << " red text" << endl;

    cin.get();
}

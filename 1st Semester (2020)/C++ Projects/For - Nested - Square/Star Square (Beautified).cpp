#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;


// Color Settings

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

basic_ostream<char> &operator<<(basic_ostream<char> &s, const setcolour &ref)
{
    SetConsoleTextAttribute(ref._console_handle, ref._c);
    return s;
}


// Main Code Below
// To Set 1 of above color,
// Enter this Between << of cout:
// setcolour(*colour*, chandle)
// Paste this in main() :
// HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);



int main(int argc, char** argv) 
{
	HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int i;
	StarSquare:
	cout << setcolour(TEAL, chandle) << "\nEnter Limit (Recommended: 1-55): " << setcolour(RED, chandle);
	cin >> i;
	cout << "\n";
	for (int x=0 ; x<=i ; x++)
	{
		for (int y=0; y<=i; y++)
		{
			cout << setcolour(GREEN, chandle) << " O";          // Use { cout << y << " "; } for a different Result!
		}
		cout << endl;
	}
	goto StarSquare;
	return 0;
}

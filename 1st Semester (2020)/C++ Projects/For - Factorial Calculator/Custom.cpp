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
	x:
	int fac = 0;
	int factorial;
	cout << setcolour(TEAL, chandle) << "\n- Enter number: " << setcolour(RED, chandle);
	cin >> factorial;
	fac = factorial;
	
	//Loop:
	
	for (int dec = fac - 1 ; dec > 1 ; dec--)
	{
		fac = fac*dec;
	}
	cout << setcolour(GREEN, chandle) << "\n- Factorial of " << factorial << " is = " << setcolour(RED, chandle) << fac << endl;
	goto x;
	return 777;
}

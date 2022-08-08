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
// setcolour(WHITE, chandle) << 
// Paste this in main() :
// HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);



int main(int argc, char** argv) 
{
	HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	system("title Initialization-Condition-Updation");
	cout << setcolour(TEAL, chandle) << "Abbreviation of ICU :" << endl;
	cout << setcolour(WHITE, chandle) << "====================\n\n";

	cout << setcolour(RED, chandle) << " I" << setcolour(GREEN, chandle) << " : Init/Integer (Number Assignment)" <<endl;
	cout << setcolour(RED, chandle) << " C" << setcolour(GREEN, chandle) << " : Condition    (something < or > or = something)" <<endl;
	cout << setcolour(RED, chandle) << " U" << setcolour(GREEN, chandle) << " : Update       (something++ , something-- , something=something*something)" <<endl;

	cout << setcolour(TEAL, chandle) << "\n\"For\" Loop" <<endl;
	cout << setcolour(WHITE, chandle) << "===========" <<endl;
	cout << setcolour(GREEN, chandle) << " for (" << setcolour(RED, chandle) << "I"  << setcolour(WHITE, chandle) << " ;"  << setcolour(RED, chandle) << " C"  << setcolour(WHITE, chandle) << " ;"  << setcolour(RED, chandle) << " U"  << setcolour(GREEN, chandle) << ")" <<endl;

	cout << setcolour(TEAL, chandle) << "\n\"While\" Loop" <<endl;
	cout << setcolour(WHITE, chandle) << "=============" <<endl;
	cout << setcolour(RED, chandle) << " I" << setcolour(GREEN, chandle) << ";" <<endl;
	cout << " while ("  << setcolour(RED, chandle) << "C"  << setcolour(GREEN, chandle) << ")" <<endl;
	cout << " {" <<endl;
	cout << "	//code" <<endl;
	cout << "	" << setcolour(RED, chandle) << "U" << setcolour(GREEN, chandle) << ";" <<endl;
	cout << " }" <<endl;

	cout << setcolour(TEAL, chandle) << "\n\"do ... While\" Loop" <<endl;
	cout << setcolour(WHITE, chandle) << "===================" <<endl;
	cout << setcolour(RED, chandle) << " I" << setcolour(GREEN, chandle) << ";" <<endl;
	cout << " do" <<endl;
	cout << " {" <<endl;
	cout << "	//Code" <<endl;
	cout << "	" << setcolour(RED, chandle) << "U" << setcolour(GREEN, chandle) << ";" <<endl;
	cout << " }" <<endl;
	cout << " while ("  << setcolour(RED, chandle) << "C"  << setcolour(GREEN, chandle) << ")" <<endl;
	system("pause");
	return 0;
}

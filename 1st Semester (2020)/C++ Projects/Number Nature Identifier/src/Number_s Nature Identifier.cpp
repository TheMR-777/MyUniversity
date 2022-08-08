//============================================================================
// Name        : Number's Nature Identifier
// Author      : ./MR_777
// Version     : 0.1 Alpha
// Copyright   : Your copyright notice
// Description : Number's Nature Identifier in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
	int a;
	cout << "Number's Nature Identifier" << endl;
	x:
	cout << "=======================================\n" << endl;
	cout << "- Enter a Number to Check: ";
	cin >> a;
	if (a%2 == 0) // Module (%) Gives the remainder value, when divided with %x value (like 2 here)
	{
		cout << "---------------------------------------" << endl;
		cout << "////// Your Number is Even! ////// \n";
	}
	else
	{
		cout << "---------------------------------------" << endl;
		cout << "////// Your Number is ODD! ////// \n";
	}
	cout << "---------------------------------------" << endl;
	cout << "- Script Created by ./MR_777" << endl;
	cout << "- ThanX 4 using my Script!" << endl;
	cout << "- Press Ctrl+C to Exit" << endl;
	if (cin.get() == '\n')
	{
		goto x;
	}
	else
	exit;
	return 777;
}

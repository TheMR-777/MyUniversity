//============================================================================
// Name        : Variable Replacement without using additional Variable
// Author      : ./MR_777
// Version     : 0.1 Alpha
// Copyright   : Your copyright notice
// Description : Variable Replacement in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
	int X,Y;
	cout << "Enter X=";
	cin >> X;
	cout << "Enter Y=";
	cin >> Y;
	cout << "\nReplacing Values ..." << endl;
	X=X+Y;
	Y=X-Y;
	X=X-Y;
	cout << "Values Replaced, Showing Results ...\n" << endl;
	cout << "X=" << X << endl;
	cout << "Y=" << Y << endl;
	return 0;
}

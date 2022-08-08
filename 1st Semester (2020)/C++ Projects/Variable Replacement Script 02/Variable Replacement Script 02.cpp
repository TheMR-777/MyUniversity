//============================================================================
// Name        : Variable Replacement using a 3rd Variable
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
	int X,Y,Z;
	cout << "Enter X=";
	cin >> X;
	cout << "Enter Y=";
	cin >> Y;
	cout << "\nReplacing Values ..." << endl;
	Z=X+Y;
	X=Z-X;
	Y=Z-Y;
	cout << "Values Changed, Showing Results ...\n" << endl;
	cout << "X=" << X << endl;
	cout << "Y=" << Y << endl;
	return 0;
}

//============================================================================
// Name        : Variable Replacement
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
	int Z=X+Y;
	int x=Z-X;
	int y=Z-Y;
	cout << "Values Changed, Showing Results ...\n" << endl;
	cout << "X=" << x << endl;
	cout << "Y=" << y << endl;
	return 0;
}

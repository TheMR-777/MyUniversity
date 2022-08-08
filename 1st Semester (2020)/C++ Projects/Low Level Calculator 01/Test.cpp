// HW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int a,b,c;
	x:
	cout << "\n====================";
	cout << "\nEnter 1st Number: ";
	cin >> a;
	cout << "\n--------------------";
	cout << "\nEnter 2nd Number: ";
	cin >> b;
	cout << "\n--------------------";
	cout << "\nEnter 3rd Number: ";
	cin >> c;
	cout << "\n--------------------";
	cout << "\n Showing Results ...";
	cout << "\n--------------------";
	cout << " \n\n - Sum: " << a + b + c << endl;
	cout << " - Product: " << a * b * c << endl;
	cout << " - Average: " << (a + b + c) / 3 << endl;
	goto x;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

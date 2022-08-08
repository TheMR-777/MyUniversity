#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// Loading

	ifstream input__file("myFile1.txt");
	ofstream output_file("myFile2.txt");
	string line;

	// Copying

	while (getline(input__file, line))
	{
		output_file << line << endl;
	}

	// Report

	cout << "Programming in an art." << endl;
}
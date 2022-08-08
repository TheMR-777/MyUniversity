#include <iostream>
#include <fstream>
#include <array>
#include <string>
using namespace std;



void Write_in(const array<string, 5>& Data)
{
	// Initialization
	// -----------

	ofstream EX_DATA(Data[0] + ".txt");

	// Data Insertion
	// -----------

	for (auto& Elem : Data)
	{
		EX_DATA << Elem << endl;
	}
}


void Search_file_for(const string& Target, const string& filename)
{
	// Initialization
	// -----------

	ifstream EX_FILE(filename);

	// Reading it
	// -----------

	string Elem;
	while (getline(EX_FILE, Elem))
	{
		if (Elem == Target)
		{
			cout << " Father's Name Found in External File : [ " << Elem << " ]" << endl;
		}
	}
}


int main()
{
	// Initialization
	// -----------

	array<string, 5> Data;

	// Information Gathering
	// -----------

	cout << endl;
	cout << "Enter the Information as asked" << endl;
	cout << "------------------------------" << endl << endl;
	cout << " Your Name : ";
	getline(cin, Data[0]);

	cout << " Your Father's Name : ";
	getline(cin, Data[1]);

	cout << " Your Class : ";
	getline(cin, Data[2]);

	cout << " Phone Number# : ";
	getline(cin, Data[3]);

	cout << " Address : ";
	getline(cin, Data[4]); cout << endl;

	// External File Writing
	// -----------

	Write_in(Data);

	// String Matching from Output File
	// -----------

	Search_file_for(Data[1], Data[0] + ".txt");
}
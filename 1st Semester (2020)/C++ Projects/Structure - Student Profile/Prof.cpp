#include <iostream>
using namespace std;


struct prof
{
	int roll;
	string name;
	int Marks[10];
};



int main()
{

	

	// Initialization

	int subn, avg;
	
	cout << "Please Enter total number of Subjects first: ";
	cin >> subn;
	
	
	prof student;

	// Intro
	
	
	start:
	system("cls");
	cout << "=====--------------------------=====" << endl;
	cout << " ... Let's Start Some Profiling ..." << endl;
	cout << " ... Enter Information as asked ..." << endl;
	cout << "=====--------------------------=====" << endl;

	// Taking Input

	cout << "\n- Enter Student's Roll Number: ";
	cin >> student.roll;
	cout << "- Enter Student's Name: ";
	cin >> student.name;

	cout << endl;

	for (int i=0 ; i < subn ; i++)
	{
		cout << "- Enter Student's Marks in Subject #" << i+1 << " : ";
		cin >> student.Marks[i];
		avg = avg + student.Marks[i];
	}

	// Printing Result

	
	system("cls");
	cout << "========-------------------========" << endl;
	cout << "//////// - Final Results - ////////" << endl;
	cout << "========-------------------========" << endl << endl;
	cout << "- Student's Name: \t" << student.name << endl;
	cout << "-----------------------------------" << endl;
	cout << "- Student's Roll: \t" << student.roll << endl;
	cout << "-----------------------------------" << endl;
	cout << "\n- Student's Marks Below:\n" << endl;

	for (int i=0 ; i < subn ; i++)
	{
		cout << "-----------------------------------" << endl;
		cout << "- Marks of Subject #" << i+1 << " are : " << student.Marks[i] << endl;
	}
	cout << "------------------------------------" << endl;

	cout << "\nAverage Marks are: " << avg/subn << endl << endl;
	cout << "------------------------------------" << endl;

	// Continue / Break

	int end;
	cout << "Enter 1 to Continue, or any other key to exit: ";
	cin >> end;
	if (end == 1) goto start;

}

































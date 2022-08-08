#include <iostream>
using namespace std;

int main()
{
	int total = 0, i = 0;

	for (int grades = 0; grades != -1; ++i)
	{
		total += grades;
		cout << "Enter the Grades of Subject #" << i + 1 << " : ";
		cin >> grades;
	}

	cout << endl;
	cout << "Average Grades are : " << total / (--i) << endl;
}
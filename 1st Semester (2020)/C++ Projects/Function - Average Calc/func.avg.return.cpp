#include <iostream>
using namespace std;



double average( double A[], int size )
{
	// Calculations
	
	int sum, avg=0;
	for (int i=0 ; i < size ; i++)
	{
		sum = sum + A[i];
	}
	
	return sum/size;
}




int main()
{
	int size;
	cout << "Enter SIZE of the Array: ";
	cin >> size;
	double A[size];
	cout << endl;
	
	cout << "----------------------------------------" << endl;
	for (int i=0 ; i < size ; i++)
	{
		cout << "Enter Value #" << i+1 << " : ";
		cin >> A[i];
	}
	
	cout << "----------------------------------------" << endl;
	cout << "Average is = " << average( A, size );
	
}

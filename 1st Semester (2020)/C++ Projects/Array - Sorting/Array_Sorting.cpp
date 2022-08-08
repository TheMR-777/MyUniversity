#include <iostream>

using namespace std;

int main()
{
	int size, temp, choice, end;
	
	SORTING:
		
	//Assinging size of Array
	
		cout << "Enter Array Size: ";
		cin >> size;
		int A[size];
	
	//Assinging Elements
	
		cout << "\nEnter Elements 1-by-1 below, as asked," << endl << endl;
		for (int i=0 ; i < size ; i++)
		{
			cout << "Enter Element #" << i+1 << " : ";
			cin >> A[i];
		}
	
	//Printing Assigned STATE
	
		cout << "\nArray in ASSIGNED state:" << endl << endl;
		for (int i=0 ; i < size ; i++)
		{
			cout << "Element #" << i+1 << " is: " << A[i];
			
			//Sorting
			
			if (i%2 == 0)
			{
				cout << "\t\t";
			}
			else
			{
				cout << endl;
			}
		}
	
	//Ascending or Descending
	
		cout << "\n\nWhich way U wanna SORT the ARRAY?" << endl << endl;
		cout << "1. Ascending" << endl;
		cout << "2. Descending" << endl;
		cout << "\n- Your Choice: ";
		cin >> choice;
	
	//Sorting Array: "A[size]" by using "temp" integer
	
		for (int i=0 ; i < (size-1) ; i++)
		{
			for (int j=(i+1) ; j < size ; j++)
			{
				if (choice == 1)
				{
					if (A[j] < A[i])
					{
						temp = A[j];
						A[j] = A[i];
						A[i] = temp;
					}
				}
				else if (choice == 2)
				{
					if (A[j] > A[i])
					{
						temp = A[j];
						A[j] = A[i];
						A[i] = temp;
					}
				}	
			}
		}
	
	//Printing Final Result
	
		cout << "\n\nArray in ";
		if (choice == 1)
		{
			cout << "ASCENDING";
		}
		else
		{
			if (choice == 2)
			{
				cout << "DESCENDING";
			}
			else
			{
				cout << "DEFAULT";
			}
		}
		
		cout <<" state: \n" << endl;
		for (int i=0 ; i < size ; i++)
		{
			cout << "Element #" << i+1 << " is: " << A[i] << endl;
		}

	// Finalize
	
		cout << "\n- Enter 1 to Continue, or any other key to EXIT: ";
		cin >> end;
		if (end == 1)
		{
			system("cls");
			goto SORTING;
		}
}

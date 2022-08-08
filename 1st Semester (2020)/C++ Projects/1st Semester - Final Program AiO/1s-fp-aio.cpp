#include <iostream>
using namespace std;




struct Profile
{
	string name;
	int Marks[10];
};




double ASUM(int A[], int size, bool op)
{
	int S=0;
	for (int i=0 ; i<size ; i++)
	{
		S = S + A[i];
	}
	
	if (op == 1)
	{
		return S;
	}
	else
	{
		return S/size;
	}
}


void SAO()
{
	int choice, size, sort,  temp;
	cout << "------------------------------------------------------------" << endl;
	cout << "- Enter Operation of the Array" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "1. Addition" << endl;
	cout << "2. Average" << endl;
	cout << "3. Sorting" << endl;
	cout << "\n- Your Choice: ";
	cin >> choice;
	
	cout << "------------------------------------------------------------" << endl;
	cout << "- Enter Array Size: ";
	cin >> size;
	int SAO[size];
	
	cout << "------------------------------------------------------------" << endl << endl;
	for (int i=0 ; i<size ; i++)
	{
		cout << "- Enter Element #" << i+1 << " : ";
		cin >> SAO[i];
	}
	
	cout << "------------------------------------------------------------" << endl;
	switch (choice)
	{
		case 1:
			{
				cout << "SUM of all the Elements is: " << ASUM(SAO, size, 1) << endl;
				break;
			}
		case 2:
			{
				cout << "Average of all the Elements is: " << ASUM(SAO, size, 0) << endl;
				break;
			}
		case 3:
			{
				cout << "In which manner, U wanna Sort the Array?" << endl;
				cout << "------------------------------------------------------------" << endl;
				cout << "1. Ascending" << endl;
				cout << "2. Descending" << endl;
				cout << "\n- Your Choice: ";
				cin >> sort;
				
				for (int i=0 ; i<(size-1) ; i++)
				{
					for (int j=(i+1) ; j<size ; j++)
					{
						if (sort == 1)
						{
							if (SAO[j] < SAO[i])
							{
								temp = SAO[j];
								SAO[j] = SAO[i];
								SAO[i] = temp;
							}
						}
						if (sort == 0)
						{
							if (SAO[j] > SAO[i])
							{
								temp = SAO[j];
								SAO[j] = SAO[i];
								SAO[i] = temp;
							}
						}
					}
				}
				
				cout << "\nSorted Array is:" << endl;
				cout << "------------------------------------------------------------" << endl;
				
				for (int i=0 ; i<size ; i++)
				{
					cout << "Element #" << i+1 << " is : " << SAO[i] << endl;
				}
				
				break;
			}
	}
}


void STDP()
{
	int choice, sub;
	cout << "Enter no. of Profiles u wanna create: ";
	cin >> choice;
	cout << "--------------------------------------------" << endl;
	Profile std[choice];
	cout << "Enter no. of Subjects per student: ";
	cin >> sub;
	system("cls");
	
	for (int i=0 ; i<choice ; i++)
	{
		cout << endl;
		cout << "--------------------------------------------" << endl;
		cout << "- Enter NAME of Student #" << i+1 << " : ";
		cin >> std[i].name;
		cout << "--------------------------------------------" << endl;
		
		for (int j=0 ; j<sub ; j++)
		{
			cout << "Enter Marks of Subject #" << j+1 << " : ";
			cin >> std[i].Marks[j];
		}
	}
	
	system("cls");
	cout << endl;
	cout << "--------------------------------------------" << endl;
	for (int i=0 ; i<choice ; i++)
	{
		cout << std[i].name << "\t Total: " << ASUM(std[i].Marks, sub, 1) << "\t Average: " << ASUM(std[i].Marks, sub, 0) << endl;
	}
}


void Pointer()
{
	string x, *P;
	cout << endl;
	cout << "----------------------------------------------" << endl;
	cout << "- Enter any Thing (Except just ENTER) : "; 
	cin >> x;
	cout << "----------------------------------------------" << endl;
	P = &x;
	
	cout << endl << "----------------------------------------------" << endl;
	cout << "Original Input: \t" << x << endl;
	cout << "Original Address: \t" << &x << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl << "----------------------------------------------" << endl;
	cout << "Pointer Indication: \t" << *P << endl;
	cout << "Pointer Address: \t" << P << endl;
	cout << "----------------------------------------------" << endl;
}


void PointerX()
{
	cout << "- Pointer Takes input in the form of Address of a certain variable." << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "- Size of Pointer depends on the OS" << endl;
	cout << "- Pointer can be created using Steric ( * ) before the name of" << endl;
	cout << "  pointer, like: int *P , or string *X , etc." << endl;
	cout << "- There are 2 points to be remembered while handling Pointers:" << endl;
	cout << "   - ' & ' Means ADDRESS" << endl;
	cout << "   - ' * ' Just Cancels the Effect of &" << endl;
	cout << "   - Example: *&X is equal to X, Similarly, &*X just means X." << endl;
	cout << "- When U make a Pointer with Steric ( * ) sign before name, u tell" << endl;
	cout << "  computer to make a POINTER which will POINT toward the variable," << endl;
	cout << "  u wanna point." << endl;
	cout << "- U can assign the Pointer towards the specific Variable like this:" << endl;
	cout << "  P = &x , where x is the variable u created before. It may be any " << endl;
	cout << "  other variable, of any name." << endl;
	cout << "- Another thing..." << endl;
	cout << "  A Pointer P already has ' & ' sign before it. For Example: " << endl;
	cout << "  A Pointer P is also equals to &P. THEY R JUST SAME." << endl;
	cout << "  But, to extract the value, which the pointer points, we have to" << endl;
	cout << "  use ' * ' before it, to cancel the effect of ' & '." << endl;
	cout << "- Check the ""Concept Only"" Section for Example of Pointer." << endl;
	cout << "\n- Thank You 4 Reading my instructions!" << endl;
	cout << "-------------------------------------------------------------------" << endl;
}


void RVFUNC()
{
	int marks;
	cout << "Enter ur Marks: ";
	cin >> marks;
	
	if (marks < 33)
	{
		cout << "Please Enter ur PASSING Marks!" << endl;
		RVFUNC();
	}
}


int status(int m)
{
	if (m < 33)
	{
		cout << "Please Enter your PASSING Marks: ";
		cin >> m;
		status(m);
	}
	else
	{
		return m;
	}
}





int main()
{
	m:
	system("cls");
	int choice;
	cout << "This is the Final Program of 1st - Semester (12.Februry.2020)." << endl;
	cout << "In this Program, I've Combined all the important Programmes related to our Syllabus.\n" << endl;
	cout << "Enter any One Operation in the following field.\n" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "1. Simple Array Operations" << endl;
	cout << "2. Student Profile using Structure" << endl;
	cout << "3. Pointer (Concept Only)" << endl;
	cout << "4. Pointer (Explaination)" << endl;
	cout << "5. Recursive Function (Enter ur Passing Marks, using VOID)" << endl;
	cout << "6. Recursive Function (Enter ur Passing Marks)" << endl;
	cout << "\n- Your Choice: ";
	cin >> choice;
	
	
	system("cls");
	switch (choice)
	{
		case 1:
			{
				SAO();
				break;
			}
		case 2:
			{
				STDP();
				break;
			}
		case 3:
			{
				Pointer();
				break;
			}
		case 4:
			{
				PointerX();
				break;
			}
		case 5:
			{
				RVFUNC();
				cout << "Now U R Passed!" << endl;
				break;
			}
		case 6:
			{
				int marks;
				cout << "Please Enter ur Marks: ";
				cin >> marks;
				
				if (status(marks) >= 33)
				{
					cout << "Now U.R. Passed!" << endl;
				}
				else
				{
					cout << "Sorry, something went wrong" << endl;
				}
			}
	}
	
	cout << endl;
	system("pause");
	goto m;
}






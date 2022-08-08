#include <iostream>
using namespace std;




struct Profile
{	
	int number;				// ID Number of Student
	string name;			// Name of Student
	double Marks[10];		// Array of Marks
	string status;			// Passed or Failed, based on Every Input Marks
};




double average(double A[] , int size)
{
	double sum=0.0;
	
	for (int i=0 ; i<size ; i++)
	{
		sum = sum + A[i];
	}
	
	return (sum/size);
}



double total(double A[] , int size)
{
	double sum=0.0;
	
	for (int i=0 ; i<size ; i++)
	{
		sum = sum + A[i];
	}
	
	return sum;
}




int main()
{
	
	// Getting Information
	
	
	int std, size, avg, temp;
	x:
	system("cls");
	cout << "Presented By:" << endl << endl << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |                                                             |" << endl;
	cout << " |  `7MMM.     ,MMF'`7MM*^*Mq.                                 |" << endl;
	cout << " |    MMMb    dPMM    MM   `MM.                                |" << endl;
	cout << " |    M YM   ,M MM    MM   ,M9    M******A'M******A'M******A'  |" << endl;
	cout << " |    M  Mb  M' MM    MMmmdM9     Y     A' Y     A' Y     A'   |" << endl;
	cout << " |    M  YM.P'  MM    MM  YM.          A'       A'       A'    |" << endl;
 	cout << " |    M  `YM'   MM    MM   `Mb.       A'       A'       A'     |" << endl;
	cout << " |  .JML. `'  .JMML..JMML. .JMM.     A'       A'       A'      |" << endl;
	cout << " |                                  A'       A'       A'       |" << endl;
 	cout << " |                         mmmmmmm A'       A'       A'        |" << endl;
 	cout << " |                                                             |" << endl;
 	cout << " +-------------------------------------------------------------+" << endl;
 	cout << "\n\n- It's a Final List Generator containing Total, Average, and\n status (PASSED/FAILED) of Students.\n- So, lets begin with providing some information about Students.\n" << endl;
	cout << "=--------------------------------------------------------------=" << endl;
	cout << "- Enter number of Students: ";
	cin >> std;
	cout << "=--------------------------------------------------------------=" << endl;
	cout << "- Enter number of Subjects (Per Student): ";
	cin >> size;
	system("cls");
	
	
	// Getting Name + Marks
	
	
	Profile student[std];
	
	for (int i=0 ; i<std ; i++)
	{
		student[i].number = i;
		cout << "========================================" << endl;
		cout << "- Enter name of Student #" << i+1 << " : ";
		cin >> student[i].name;
		
		for (int j=0 ; j<size ; j++)
		{
			cout << "----------------------------------------" << endl;
			cout << "- Enter Marks of " << student[i].name << "'s Subject #" << j+1 << " : ";
			cin >> student[i].Marks[j];
			
			if (student[i].Marks[j] < 33)
			{
				student[i].status = "FAILED";
			}
		}
		system("cls");
	}
	
	
	// Sorting Array by using "temp" integer
	
	
	for (int i=0 ; i < (std-1) ; i++)
	{
		for (int j=(i+1) ; j < std ; j++)
		{
			if (total(student[j].Marks, size) > total(student[i].Marks, size))
			{
				temp = student[j].number;
				student[j].number = student[i].number;
				student[i].number = temp;
			}	
		}
	}
	system("cls");
	
	
	// Results:
	
	
	cout << "The top Students are:" << endl;
	
	cout << "-----------------------------------------------------------------------" << endl;
	
	for(int i=0 ; i < std ; i++)
	{
		cout << "Total: " << total(student[student[i].number].Marks, size) << "\t" << "Average: " << average(student[student[i].number].Marks, size) << "\t" << "Name: " << student[student[i].number].name /*<< "\t" << "ID #" << (student[i].number + 1)*/ << "\t";
		
		// Status
		
		cout << "Status: ";
		
		if (student[student[i].number].status == "FAILED")
		{
			cout << student[student[i].number].status << endl;
		}
		else
		{
			cout << "PASSED" << endl;
		}
	}
	
	cout << "-----------------------------------------------------------------------" << endl;
	
	
	
	system("pause");
	goto x;
}















// Presented By:
//                                                              
//                                                              
//  `7MMM.     ,MMF'`7MM"""Mq.                                  
//    MMMb    dPMM    MM   `MM.                                 
//    M YM   ,M MM    MM   ,M9      M******A'M******A'M******A' 
//    M  Mb  M' MM    MMmmdM9       Y     A' Y     A' Y     A'  
//    M  YM.P'  MM    MM  YM.            A'       A'       A'   
//    M  `YM'   MM    MM   `Mb.         A'       A'       A'    
//  .JML. `'  .JMML..JMML. .JMM.       A'       A'       A'     
//                                    A'       A'       A'      
//                           mmmmmmm A'       A'       A'       


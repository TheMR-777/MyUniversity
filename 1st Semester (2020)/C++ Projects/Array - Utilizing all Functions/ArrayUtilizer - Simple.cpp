#include <iostream>
#include <limits>
using namespace std;


int main() 
{
	
	cout << " +---------------------------------------------------------------+" << endl;
	cout << " |                                                               |" << endl;
	cout << " |  `7MMM.     ,MMF'`7MM&&&Mq.                                   |" << endl;
	cout << " |    MMMb    dPMM    MM   `MM.                                  |" << endl;
	cout << " |    M YM   ,M MM    MM   ,M9      M******A'M******A'M******A'  |" << endl;
	cout << " |    M  Mb  M' MM    MMmmdM9       Y     A' Y     A' Y     A'   |" << endl;
	cout << " |    M  YM.P'  MM    MM  YM.            A'       A'       A'    |" << endl;
 	cout << " |    M  `YM'   MM    MM   `Mb.         A'       A'       A'     |" << endl;
	cout << " |  .JML. `'  .JMML..JMML. .JMM.       A'       A'       A'      |" << endl;
	cout << " |                                    A'       A'       A'       |" << endl;
 	cout << " |                           mmmmmmm A'       A'       A'        |" << endl;
 	cout << " |                                                               |" << endl;
 	cout << " +---------------------------------------------------------------+" << endl;
	
	
	
	
	
	
	
	system("title Array Utilizer");
	cout << "\nIt's an Array Utilizer." << endl;
	cout << "=======================" << endl;
	int choice;
	
	x:
	cout << "\n- Choose Operation:\n" << endl;
	cout << "1. SUM/Product/Average Calculator." << endl;
	cout << "2. Minumum & Maximum Integer Finder." << endl;
	cout << "3. Factorial Finder (A) - Decrement." << endl;
	cout << "4. Factorial Finder (B) - Increment & Can show Large Values." << endl;
	cout << "5. Number's Nature Identifier (Even/Odd)." << endl;
	cout << "6. Multiplication Table Generator." << endl;
	cout << "7. Result Card Generator (BETA)." << endl;
	cout << "\n- Your Choice: ";
	cin >> choice;
	
	//Choice Chekker:
	
	if (choice > 0 && choice < 8)
	{
	
	system("cls");
	switch (choice)
	{
		case 1:
			{
				SPA:
				int amnt, sum=0 ; long pro=1;
				cout << "\n- Enter amount of Integers to be Entered: ";
				cin >> amnt;
				cout << endl;
				
				//Array Initialization, Integer Assignment & Calculation
				
				int SPA[amnt];
				for (int i=0 ; i < amnt ; i++)
				{
					cout << "Enter Number: (" << i+1 << "): ";
					cin >> SPA[i];
					sum = sum + SPA[i];
					pro = pro * SPA[i];
				}
				
				//Showing Results
				
				cout << endl;
				cout << "----------------------------------------" << endl;
				cout << "The     SUM     of " << amnt << " Integers is: " << sum << endl;
				cout << "The   Product   of " << amnt << " Integers is: " << pro << endl;
				cout << "The   Average   of " << amnt << " Integers is: "  << sum/amnt << endl;
				cout << "----------------------------------------" << endl;
				
				//Continue / Break
				
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto SPA;
				}
				
				break;
			}
		case 2:
			{
				MINMAX:
				int max, min, amnt;
				cout << "\n- Enter amount of Integers to be Entered: ";
				cin >> amnt;
				cout << endl;
				
				int MINMAX[amnt];
				for (int i=0 ; i < amnt ; i++)
				{
					cout << "Enter Number: (" << i+1 << "): ";
					cin >> MINMAX[i];
				}
				
				cout << endl;
				
				//Checking
				/*
				for (int i=0 ; i < amnt ; i++)
				{
					cout << MINMAX[i] << "\t";
				}
				*/
				
				//Maximum Finder
				
				max = MINMAX[0];
				for (int i=0 ; i < amnt ; i++)
				{
					if (max < MINMAX[i])
					{
						max = MINMAX[i];
					}
				}
				cout << "---------------------------------------" << endl;
				cout << "Maximum Number is: " << max << endl;
				
				//Minimum Finder
				
				min = MINMAX[0];
				for (int i=0 ; i < amnt ; i++)
				{
					if (min > MINMAX[i])
					{
						min = MINMAX[i];
					}
				}
				cout << "---------------------------------------" << endl;
				cout << "Minimum Number is: " << min << endl;
				
				//Continue / Break
				
				cout << "---------------------------------------" << endl;
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto MINMAX;
				}
				
				//Ending
				
				break;
			}
		case 3:
			{
				FACTORIAL:
				int fac = 0, factorial;
				cout << "\nEnter the Desired Number: ";
				cin >> factorial;
				fac = factorial;
				
				//Calculation:
	
				for (int dec = fac - 1 ; dec > 1 ; dec--)
				{
					fac = fac*dec;
				}
				cout << "\n---------------------------------------" << endl;
				cout << "- Factorial of " << factorial << " is = " << fac << endl;
				
				//Continue / Break
				
				cout << "---------------------------------------" << endl;
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto FACTORIAL;
				}
				
				//Break...!!!
				
				break;
			}
		case 4:
			{
				FACTORIALB:
				int fac;
				double mem = numeric_limits<double>::infinity();
				mem=1;
				cout << "\nEnter the Desired Number: ";
				cin >> fac;
				
				for (int i=1 ; i<=fac ; i++)
				{
					(mem = mem * i) ;
				}
				cout << "\n---------------------------------------" << endl;
				cout << "Your Factorial: " << mem << endl;
				
				//Continue / Break
				
				cout << "---------------------------------------" << endl;
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto FACTORIALB;
				}
				
				//HandBreak
				
				break;
			}
		case 5:
			{
				EVENODD:
				int n;
				cout << "\nEnter any / desired Number: ";
				cin >> n;
				cout << endl;
				
				//Detection by Modulation
				
				if (n%2 == 0)
				{
					cout << "---------------------------------------" << endl;
					cout << "////// Your Number is Even! ////// \n";
				}
				else
				{
					cout << "---------------------------------------" << endl;
					cout << "////// Your Number is ODD! ////// \n";
				}
				
				//Continue / Break
				
				cout << "---------------------------------------" << endl;
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto EVENODD;
				}
				
				//Mayday ... Mayday ... Breaking Case ... I'm Braking Case, OUT! .
				
				break;
			}
		case 6:
			{
				HighTable:
				int in, lim;
				cout << "\nEnter the desired Number: ";
				cin >> in;
				cout << "Enter Maximum Limit of Table: ";
				cin >> lim;
				cout << "\n- Table of " << in << " :" << endl;
				cout << "=======================" << endl;
				int i=1;
				while(i<=lim)
 			   {
 			       cout << "   " << in << " x " << i << " = " << in*i << endl;
			        i++;
 			   }
				cout << "-----------------------" << endl;
				
				//Continue / Break
				
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto HighTable;
				}
				
				//Under the Table, Break the Table
				
				break;
			}
		case 7:
			{
				ResultCard:
				
				//Initialization of String Array 4 Subjucts
				int sub; char caution;
				cout << "\nEnter Number of Subjects: ";
				cin >> sub;
				cout << endl;
				
				string subarr[sub];
				int numarr[sub];
				int total[sub];
				
				//Assignment in String Array
				
				cout << "Enter Subjects Name below 1-by-1, (shorter is better):\n" << endl;
				for (int i=0 ; i<sub ; i++)
				{
					cout << "What's Subject Number: (" << i+1 << ") = ";
					cin >> subarr[i];
				}
				
				cout << endl;
				
				//Final Check
				
				for (int i=0 ; i<sub ; i++)
				{
					cout << "Subject Number: (" << i+1 << ") is [ " << subarr[i] << " ]" << endl;
				}
				cout << endl;
				cout << "Is this Information Correct? Proceed? (0=no , any other key for yes): ";
				cin >> caution;
				
				if (caution == '0')
				{
					cout << "Be careful this Time..." << endl;
					goto ResultCard;
				}
				
				//Numbers Assignment (Obtained & Total)
				
				cout << endl;
				system("cls");
				for (int i=0 ; i<sub ; i++)
				{
					cout << "---------------------------------------" << endl;
					cout << " - Enter Marks of [ " << subarr[i] << " ]" << endl;
					cout << "\n\tObtained: ";
					cin >> numarr[i];
					cout << "\tTotal   : ";
					cin >> total[i];
				}
				
				//Card Generation:
				
				system("cls");
				cout << "---------------------------------------" << endl;
				cout << "Check the Final Result:" << endl;
				cout << endl;
				
				for (int i=0 ; i<sub ; i++)
				{
					double per;
					cout << "---------------------------------------------------------------------" << endl;
					cout << " Total Marks: " << total[i] << " \tObtained Marks: " << numarr[i] << "\tSubject: " << subarr[i]  << " \t " << ((numarr[i]*100) / total[i]) << "%" << endl;
				}
				cout << "---------------------------------------------------------------------" << endl;
				break;
			}
	}
	
	}
	
	else
	{
		system("cls");
		cout << "Invalid Input!" << endl;
	}
	
	
	cout << "\n\n----------------------------------------" << endl;
	cout << "-     Script Created by  ./MR_777" << endl;
	cout << "-      ThanX 4 using my Script!" << endl;
	cout << "-        Press Ctrl+C to Exit" << endl;
	cout << "=======================================\n" << endl;
	
	goto x;
	return 0;
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








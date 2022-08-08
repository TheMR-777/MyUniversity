#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;


// Color Settings

enum colour { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

struct setcolour
{
   colour _c;
   HANDLE _console_handle;


       setcolour(colour c, HANDLE console_handle)
           : _c(c), _console_handle(0)
       { 
           _console_handle = console_handle;
       }
};

basic_ostream<char> &operator<<(basic_ostream<char> &s, const setcolour &ref)
{
    SetConsoleTextAttribute(ref._console_handle, ref._c);
    return s;
}


// Main Code Below
// To Set 1 of above color,
// Enter this Between << of cout:
// setcolour(*colour*, chandle)
// Example: cout << setcolour(GREEN, chandle) << "Hi" << endl;
// 1st, Paste this in main() :
// HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);



int main() 
{
	// Window Resize:
	
	system("mode 100,40");   //Set mode to ensure window does not exceed buffer size
	SMALL_RECT WinRect = {0, 0, 100, 40};   //New dimensions for window in 8x12 pixel chars
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window
	
	// Main Code Below:
	
	
	
	HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << setcolour(GREEN, chandle);
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
	
	
	
	
	
	
	
	cout << setcolour(GREEN, chandle);
	system("title MR_777");
	cout << "\nIt's MR_777 's Script." << endl;
	cout << "=======================" << endl;
	int choice;
	
	x:
	cout << setcolour(GREEN, chandle);
	cout << "\n- Choose Operation:\n" << endl;
	cout << setcolour(BLUE, chandle) << " 1" << setcolour(WHITE, chandle) << ". // | SUM/Product/Average Calculator." << endl;
	cout << setcolour(BLUE, chandle) << " 2" << setcolour(WHITE, chandle) << ". \\\\ | Minumum & Maximum Integer Finder." << endl;
	cout << setcolour(BLUE, chandle) << " 3" << setcolour(WHITE, chandle) << ". // | Factorial Finder (A) - Decrement." << endl;
	cout << setcolour(BLUE, chandle) << " 4" << setcolour(WHITE, chandle) << ". \\\\ | Factorial Finder (B) - Increment." << endl;
	cout << setcolour(BLUE, chandle) << " 5" << setcolour(WHITE, chandle) << ". // | Number's Nature Identifier (Even/Odd)." << endl;
	cout << setcolour(BLUE, chandle) << " 6" << setcolour(WHITE, chandle) << ". \\\\ | Multiplication Table Generator." << endl;
	cout << setcolour(BLUE, chandle) << " 7" << setcolour(WHITE, chandle) << ". // | Result Card Generator (BETA)." << endl;
	cout << setcolour(BLUE, chandle) << " 8" << setcolour(WHITE, chandle) << ". \\\\ | Exponential Function Calculator" << endl;
	cout << setcolour(BLUE, chandle) << " 9" << setcolour(WHITE, chandle) << ". // | EasyLoad Calculator" << endl;
	cout << setcolour(BLUE, chandle) << "10" << setcolour(WHITE, chandle) << ". \\\\ | Array Sorter (Ascending/Descending)" << endl;
	cout << setcolour(GREEN, chandle) << "\n- Your Choice (Number Only): " << setcolour(BLUE, chandle);
	cin >> choice;
	
	//Choice Chekker:
	
	cout << setcolour(WHITE, chandle);
	if (choice > 0 && choice < 11 || choice == 777)
	{
	
	system("cls");
	switch (choice)
	{
		case 1:
			{
				SPA:
				int amnt, sum=0 ; unsigned long long int pro=1;
				cout << "\n- Enter amount of Integers to be Entered: ";
				cin >> amnt;
				cout << endl;
				
				if (amnt == 0)
				{
					system("cls");
					cout << "What do you mean by 0 ...???\nRestarting ..." << endl;
					goto SPA;
				}
				
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
				cout << "The   Average   of " << amnt << " Integers is: " << sum/amnt << endl;
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
				
				system("cls");
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
				
				system("cls");
				break;
			}
		case 3:
			{
				FACTORIAL:
				unsigned long long int fac = 0; int factorial;
				cout << setcolour(TEAL, chandle) << "\nEnter the Desired Number: " << setcolour(RED, chandle);
				cin >> factorial;
				fac = factorial;
				
				//Calculation:
	
				for (int dec = fac - 1 ; dec > 1 ; dec--)
				{
					fac = fac*dec;
				}
				cout << setcolour(WHITE, chandle) << "\n---------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << "- Factorial of " << factorial << " is = " << setcolour(RED, chandle) << fac << endl;
				cout << setcolour(WHITE, chandle);
				
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
				
				system("cls");
				break;
			}
		case 4:
			{
				FACTORIALB:
				int fac;
				unsigned long long int mem;
				mem=1;
				cout << setcolour(TEAL, chandle) << "\nEnter the Desired Number: " << setcolour(RED, chandle);
				cin >> fac;
				
				for (int i=1 ; i<=fac ; i++)
				{
					(mem = mem * i) ;
				}
				cout << setcolour(WHITE, chandle) << "\n---------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << "- Factorial of " << fac << " is = " << setcolour(RED, chandle) << mem << endl;
				
				//Continue / Break
				
				cout << setcolour(WHITE, chandle) << "---------------------------------------" << endl;
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto FACTORIALB;
				}
				
				//HandBreak
				
				system("cls");
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
					cout << "-----------------------------------" << endl;
					cout << "////// Your Number is Even! ////// \n";
				}
				else
				{
					cout << "-----------------------------------" << endl;
					cout << "////// Your Number is ODD! ////// \n";
				}
				
				//Continue / Break
				
				cout << "-----------------------------------" << endl;
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto EVENODD;
				}
				
				//Mayday ... Mayday ... Breaking Case ... I'm Braking Case, OUT! .
				
				system("cls");
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
				
				system("cls");
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
					cout << "-----------------------------------------------------------------------------" << endl;
					cout << " Total Marks: " << total[i] << " \tObtained Marks: " << numarr[i] << "\tSubject: " << subarr[i]  << " \t " << ((numarr[i]*100) / total[i]) << "%" << endl;
				}
				cout << "-----------------------------------------------------------------------------" << endl;
				
				//Continue / Break
				
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto ResultCard;
				}
				
				system("cls");
				break;
			}
			
		case 8:
			{
				power:
				double base, expo;
				unsigned long long int powr;
				cout << setcolour(GREEN, chandle) << "=========================================" << endl;
				cout << setcolour(RED, chandle) << "=-->" << setcolour(GREEN, chandle) << " Exponential Function Calculator " << setcolour(RED, chandle) << "<--=" << endl;
				cout << setcolour(GREEN, chandle) << "=========================================" << endl;
				cout << setcolour(GREEN, chandle) << "\n- Enter Base: " << setcolour(RED, chandle);
				cin >> base;
				cout << setcolour(GREEN, chandle) << "-----------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << "- Enter Exponent: " << setcolour(RED, chandle) ;
				cin >> expo;
				cout << setcolour(GREEN, chandle) << "-----------------------------------------" << endl;
				powr = pow(base, expo);
				cout << setcolour(GREEN, chandle) << "- Your Answer: " << base << " ^ " << expo << " = " << setcolour(RED, chandle) << powr << setcolour(GREEN, chandle) << endl;
				
				//Continue / Break
				
				cout << setcolour(GREEN, chandle) << "-----------------------------------------" << endl;
				cout << "\n- Enter 1 to Continue, or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				
				if (decision == '1')
				{
					system("cls");
					goto power;
				}
				
				system("cls");
				break;
			}
			
		case 10:
			{
				int size, temp, choice, end;
	
				SORTING:
		
				//Assinging size of Array
	
				cout << setcolour(GREEN, chandle) << "Enter Array Size: " <<  setcolour(RED, chandle);
				cin >> size;
				int A[size];
	
				//Assinging Elements
	
				cout << setcolour(GREEN, chandle) << "\nEnter Elements 1-by-1 below, as asked," << endl << endl;
				for (int i=0 ; i < size ; i++)
				{
					cout << setcolour(GREEN, chandle) << "Enter Element #" << i+1 << " : " <<  setcolour(TEAL, chandle);
					cin >> A[i];
				}
				
				//Printing Assigned STATE
				
				system("cls");
				cout << setcolour(GREEN, chandle) << "\nArray in ASSIGNED state:" << endl << endl;
				for (int i=0 ; i < size ; i++)
				{
					cout << setcolour(GREEN, chandle) << "Element #" << i+1 << " is: " << setcolour(TEAL, chandle) << A[i] << endl;
		
					/*Sorting
		
					if (i%2 == 0)
					{
						cout << "\t\t";
					}
					else
					{
							cout << endl;
					}
					*/
				}
	
				//Ascending or Descending
	
				cout << setcolour(GREEN, chandle) << "\n\nWhich way U wanna SORT the ARRAY?" << endl << endl;
				cout << setcolour(RED, chandle) << "1" << setcolour(GREEN, chandle) << ". Ascending" << endl;
				cout << setcolour(RED, chandle) << "2" << setcolour(GREEN, chandle) << ". Descending" << endl;
				cout << setcolour(GREEN, chandle) << "\n- Your Choice: "<< setcolour(RED, chandle) ;
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
	
				cout << setcolour(GREEN, chandle) << "\n\nArray in " <<  setcolour(RED, chandle) ;
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
	
				cout << setcolour(GREEN, chandle) << " state: \n" << endl;
				for (int i=0 ; i < size ; i++)
				{
					cout << setcolour(GREEN, chandle) << "Element #" << i+1 << " is: " << setcolour(RED, chandle) << A[i] << endl;
				}
	
				cout << setcolour(GREEN, chandle) << "\n- Enter 1 to Continue, or any other key to go back no Main Menu: ";
				cin >> end;
				if (end == 1)
				{
					system("cls");
					goto SORTING;
				}
				
				system("cls");
				break;
				
			}
			
			
			
			
			case 777:
				{
					cout << setcolour(GREEN, chandle);
					cout << "Presented By: \n"<< endl;
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
 					cout << setcolour(TEAL, chandle) << "\n- Congratulations! You found the Secret!" << endl;
 					cout << "- It`s " << setcolour(GREEN, chandle) << "MR_777" << setcolour(TEAL, chandle) << " , THE Creator of this Little All in One Program :)" << endl;
 					cout << setcolour(TEAL, chandle) << "- If you find any BUGS or Mistakes, Then tell me on my WhatsApp:    " << setcolour(YELLOW, chandle) << "+92 314 5401405" << endl;
 					cout << setcolour(TEAL, chandle) << "- I`ve Created some Guides, You may like `em:  " << setcolour(YELLOW, chandle) << "bit.ly/H4ck3R_777" << setcolour(GREEN, chandle) << "  or  " << setcolour(YELLOW, chandle) << "bit.ly/MR_777" << endl;
 					cout << setcolour(WHITE, chandle) << "\n  Thank You 4 Using my Script!\n" << endl;
 					cout << setcolour(WHITE, chandle);
 					
 					cout << endl;
 					system("pause");
 					system ("cls");
 					break;
				}
				
			case 9:
				{
					double TaxV=11.111;
					EasyLoad:
					int load;char choice;
					cout << setcolour(GREEN, chandle) << "============================================" << endl;
					cout << setcolour(RED, chandle) << "     ////////" << setcolour(GREEN, chandle) << " Easyload Helper! " << setcolour(RED, chandle) << "////////" << endl;
					cout << setcolour(GREEN, chandle) << "============================================" << endl;
					
					cout << setcolour(GREEN, chandle) << "\nChoose Operation: \n";
					
					cout << setcolour(RED, chandle) << "\n1" << setcolour(GREEN, chandle) <<". Input  (Rs. Load)  ->   Output (Account)" << endl;
					cout << setcolour(RED, chandle) << "2" << setcolour(GREEN, chandle) <<". Output (Required)  ->   Input  (Rs.Load)" << endl;
					cout << setcolour(RED, chandle) << "3" << setcolour(GREEN, chandle) <<". To go back to Main Menu" << endl;
					cout << setcolour(RED, chandle) << "0" << setcolour(GREEN, chandle) <<". To Change TAX %age ( Default: " << TaxV << " % )" << endl;
					
					cout << setcolour(GREEN, chandle) << "\nYour Choice: " << setcolour(RED, chandle);
					cin >> choice;
					cout << endl;
					system("cls");
					
					switch (choice)
					{
						case '1':
							{
								cout << setcolour(GREEN, chandle) << "\n- Enter EasyLoad Amount: " << setcolour(RED, chandle);
								cin >> load;
								cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
								cout << setcolour(GREEN, chandle) << " =>>---> Amount you will Recieve: " << setcolour(RED, chandle) << load - ((load*TaxV)/100) << endl;
								cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
								cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << TaxV << " % ]" << endl;
						
								//Continue / Break
					
								cout << setcolour(GREEN, chandle) << "\n- Enter 1 to Continue,\n- Enter 0 to change Tax Value,\n or Any Other Key to go back to Main Menu - ";
								char decision;
								cin >> decision;
						
								if (decision == '1')
								{
									system("cls");
									goto EasyLoad;
								}
								if (decision == '0')
								{
									system("cls");
									cout << "Enter Your TAX %age: ";
									cin >> TaxV;
									system("cls");
									goto EasyLoad;
								}
								
								system("cls");
								break;
							}
							
						case '2':
							{
								cout << setcolour(GREEN, chandle) << "\n- Enter amount U wanna Recieve in ur Account: " << setcolour(RED, chandle);
								cin >> load;
								cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
								cout << setcolour(GREEN, chandle) << " =>>---> Amount you have to Load: " << setcolour(RED, chandle) << load + ((load*TaxV)/100) << endl;
								cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
								cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << TaxV << " % ]" << endl;
						
								//Continue / Break
					
								cout << setcolour(GREEN, chandle) << "\n- Enter 1 to Continue,\n- Enter 0 to change Tax Value,\n or Any Other Key to go back to Main Menu - ";
								char decision;
								cin >> decision;
						
								if (decision == '1')
								{
									system("cls");
									goto EasyLoad;
								}
								if (decision == '0')
								{
									system("cls");
									cout << "Enter Your TAX %age: ";
									cin >> TaxV;
									system("cls");
									goto EasyLoad;
								}
								
								system("cls");
								break;
							}
							
						case '3': 
						{
							break;
						}
							
						case '0':
							{
								cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << setcolour(RED, chandle) << TaxV << " %" << setcolour(GREEN, chandle) << " ]" << endl;
								cout << "--------------------------------------" << endl;
								cout << "Enter Your TAX %age: " << setcolour(RED, chandle);
								cin >> TaxV;
								system("cls");
								goto EasyLoad;
								break;
							}
							
						default :
							{
								system("cls");
								cout << "Invalid Input!" << endl << endl;
								goto EasyLoad;
								break;
							}
					}
					system("cls");
				}
	}
	
	}
	
	else
	{
		system("cls");
		cout << setcolour(RED, chandle) << "Invalid Input!" << setcolour(WHITE, chandle) << endl;
	}
	
	
	
	cout << setcolour(GREEN, chandle);
	cout << "\n\n----------------------------------------" << endl;
	cout << ">-    Script Created by  ./" << setcolour(DARKGREEN, chandle) << "MR_777     -<" << endl;
	cout << ">--    ThanX 4 using my Script!      --<" << endl;
	cout << ">---     Press Ctrl+C to Exit       ---<" << endl;
	cout << "========================================\n" << endl;
	cout << setcolour(WHITE, chandle);
	
	goto x;
	return 777;
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








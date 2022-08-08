#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
using namespace std;



int no_random()
{
	srand(time(NULL));
	return (rand() % 101);
}


string HighScore(int comp)
{
	int HS_Var; string rtrn; stringstream sstrm;
	ifstream iHS ("HighScore.txt");
	iHS >> HS_Var;
	
	if ( comp < HS_Var )
	{
		ofstream oHS ("HighScore.txt");
		oHS << comp;

		if (oHS.is_open())
		{
			sstrm << comp;
			sstrm >> rtrn;
			return rtrn;
		} 
		else
		{
			return "Unable to Update High Score File";
		}
	}
	else
	{
		sstrm << HS_Var;
		sstrm >> rtrn;
		return rtrn;
	}
}


void game()
{
	int rdm = no_random() , guess;
	vector<int> Track;

	
	cout << endl;
	cout << "+---------------------------------------------------------------------+" << endl;
	cout << "| Guess the Number: ";
	cin >> guess;
	Track.push_back(guess);
	
	loop:
	if (guess == rdm)
	{
		
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "|               	       		                             ||" << endl;
		cout << "| Wow! You Got Me! The Number was: \t" << rdm << "		             ||" << endl;
		cout << "|               	       		                             ||" << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "| Your Guessed Numbers:                                              ||" << endl;
		cout << "| ";
		
		for (int i=0 ; i < Track.size() ; i++)
		{
			cout << Track[i];
			
			if  (i < (Track.size() - 1))
			{
				cout << ", ";
			}
		}
		cout << endl;
		
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "| Total Guesses: " << Track.size() << "\t\tHighScore: " << HighScore(Track.size()) << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << endl;
		system("pause");
	}
	else
	{
		if (guess < rdm)
		{
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|               	       		                              |" << endl;
			cout << "| My  Number is 	GREATER		 than Your Number.            |" << endl;
			cout << "|               	       		                              |" << endl;
		}
		else
		{
			if (guess > rdm)
			{
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|               	       		                              |" << endl;
				cout << "| My  Number is 	SMALLER		 than Your Number.            |" << endl;
				cout << "|               	       		                              |" << endl;
			}
		}
		
		cout << "|---------------------------------------------------------------------|" << endl;
		cout << "| Enter Other Number:\t";
		cin >> guess;
		Track.push_back(guess);
		goto loop;
	}
	
}



int main()
{
	string choice;
	
	
	// Presented By
	
	
	cout << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |                        Presented By                         |" << endl;
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
 	cout << "\n\n\n" << endl;
 	system("timeout 5");
	
	
	// Main Menu
	
	
	do
	{
		system("cls");
		cout << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "|                     This is a Guessing Game.                        |" << endl;
		cout << "|    The Number Generated by the System will be in between 0-100.     |" << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "| - Enter 0 to Quit                                                   |" << endl;
		cout << "| - Enter Any other key to \"Play The Game\"                            |" << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "\n- Your Choice: ";
		getline(cin, choice);
		
		if (choice != "0")
		{
			game();
		}
		else
		{
			return 0;
		}
	}
	while (choice != "0");
}

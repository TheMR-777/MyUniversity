#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
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

basic_ostream<char>& operator<<(basic_ostream<char>& s, const setcolour& ref)
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















namespace utils
{
	int no_random()
	{
		srand(time(NULL));
		return (rand() % 101);
	}

	string HighScore(int comp)
	{
		int HS_Var; string rtrn; stringstream sstrm;
		ifstream iHS("HighScore.txt");
		iHS >> HS_Var;

		if (comp < HS_Var)
		{
			ofstream oHS("HighScore.txt");
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
}

namespace MAIN
{
	void EasyLoad()
	{
		HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
		float TaxV;

		// Tax Management

		ifstream iTax("TaX.txt");
		iTax >> TaxV;

		if (TaxV == 0)
		{
			TaxV = 12.5;
		}

		// Main Code

		EasyLoad:
		int load; char choice;
		cout << setcolour(GREEN, chandle) << "============================================" << endl;
		cout << setcolour(RED, chandle) << "     ////////" << setcolour(GREEN, chandle) << " Easyload Helper! " << setcolour(RED, chandle) << "////////" << endl;
		cout << setcolour(GREEN, chandle) << "============================================" << endl;

		cout << setcolour(GREEN, chandle) << "\nChoose Operation: \n";

		cout << setcolour(RED, chandle) << "\n1" << setcolour(GREEN, chandle) << ". Input  (Rs. Load)  ->   Output (Account)" << endl;
		cout << setcolour(RED, chandle) << "2" << setcolour(GREEN, chandle) << ". Output (Required)  ->   Input  (Rs.Load)" << endl;
		cout << setcolour(RED, chandle) << "3" << setcolour(GREEN, chandle) << ". To go back to Main Menu" << endl;
		cout << setcolour(RED, chandle) << "0" << setcolour(GREEN, chandle) << ". To Change TAX %age   ( Default: " << TaxV << " % )" << endl;

		cout << setcolour(GREEN, chandle) << "\nYour Choice: " << setcolour(RED, chandle);
		cin >> choice;
		cin.clear();
		cin.sync();
		cout << endl;
		system("cls");

		switch (choice)
		{
			case '1':
			{
				cout << setcolour(GREEN, chandle) << "\n- Enter EasyLoad Amount: " << setcolour(RED, chandle);
				cin >> load;
				cin.clear();
				cin.sync();
				cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << " =>>---> Amount you will Recieve: " << setcolour(RED, chandle) << load - ((load * TaxV) / 100) << endl;
				cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << TaxV << " % ]" << endl;

				//Continue / Break

				cout << setcolour(GREEN, chandle) << "\n- Enter 1 to Continue,\n- Enter 0 to change Tax Value,\n or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				cin.clear();
				cin.sync();

				if (decision == '1')
				{
					system("cls");
					goto EasyLoad;
				}
				else if (decision == '0')
				{
					system("cls");
					cout << "Enter Your TAX %age: ";
					cin >> TaxV;
					cin.clear();
					cin.sync();
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
				cin.clear();
				cin.sync();
				cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << " =>>---> Amount you have to Load: " << setcolour(RED, chandle) << load + ((load * TaxV) / 100) << endl;
				cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << TaxV << " % ]" << endl;

				//Continue / Break

				cout << setcolour(GREEN, chandle) << "\n- Enter 1 to Continue,\n- Enter 0 to change Tax Value,\n or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision;
				cin.clear();
				cin.sync();

				if (decision == '1')
				{
					system("cls");
					goto EasyLoad;
				}
				else if (decision == '0')
				{
					system("cls");
					cout << "Enter Your TAX %age: ";
					cin >> TaxV;
					cin.clear();
					cin.sync();
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
				ofstream oTax("TaX.txt");
				cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << setcolour(RED, chandle) << TaxV << " %" << setcolour(GREEN, chandle) << " ]" << endl;
				cout << "--------------------------------------" << endl;
				cout << "Enter Your TAX %age: " << setcolour(RED, chandle);
				cin >> TaxV;
				cin.clear();
				cin.sync();
				oTax << TaxV;
				system("cls");
				goto EasyLoad;
				break;
			}

			default:
			{
				system("cls");
				cout << "Invalid Input!" << endl << endl;
				goto EasyLoad;
				break;
			}
		}
		system("cls");
	}

	void Extractor()
	{
		// Initialization

			string stg, prop;
			stringstream sss;
			vector<int> value;
			int I;

		// Taking Input

			system("cls");
			cout << endl;
			cout << " +----------------------------------------------------+" << endl;
			cout << " |               Enter any String Below               |" << endl;
			cout << " +----------------------------------------------------+" << endl;
			cout << " | Input : ";
			std::getline(cin, stg);
			// cin >> stg;
			cin.clear();
			cin.sync();

		// To Exit

			if (stg == "000")
			{
				system("cls");
				return;
			}

		// Value Extraction Process

			for (int i = 0; i < stg.size(); i++)
			{
				if (stg[i] >= '0' && stg[i] <= '9')
				{
					while (stg[i] >= '0' && stg[i] <= '9')
					{
						prop = prop + stg[i];
						i++;
					}
					sss << prop;
					sss >> I;
					sss = stringstream();
					value.push_back(I);
					prop = "";
				}
			}

		// Output

			cout << " |----------------------------------------------------|" << endl;

			if (value.empty())
			{
				cout << " | No Value Found in the Entered String!" << endl;
			}
			else
			{
				for (int i = 0; i < value.size(); i++)
				{
					cout << " | Value #" << i + 1 << " : " << value[i] << endl;
				}
			}
			cout << " +----------------------------------------------------+" << endl;


		// Recursive

			cout << endl;
			system("pause");
			system("cls");
	}

	void Guess_Game_main()
	{
		int rdm = utils::no_random(), guess;
		vector<int> Track;


		cout << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "| Guess the Number: ";
		cin >> guess;
		Track.push_back(guess);
		cin.clear();
		cin.sync();

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

			for (int i = 0; i < Track.size(); i++)
			{
				cout << Track[i];

				if (i < (Track.size() - 1))
				{
					cout << ", ";
				}
			}
			cout << endl;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "| Total Guesses: " << Track.size() << "\t\tHighScore: " << utils::HighScore(Track.size()) << endl;
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
			cin.clear();
			cin.sync();
			goto loop;
		}
	}

	void Guess_Game_start()
	{
		// Initialization

			string choice;

		// Main

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
				getline(cin , choice);
				cin.clear();
				cin.sync();

				if (choice != "0")
				{
					MAIN::Guess_Game_main();
				}
				else
				{
					break;
				}
			} while (choice != "0");

		// Returning

			system("cls");
	}

}

namespace Secrets
{
	void SecretMSG()
	{
		HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << setcolour(GREEN, chandle);
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
		cout << setcolour(TEAL, chandle) << "\n- Congratulations! You found a Secret!" << endl;
		cout << "- It`s " << setcolour(GREEN, chandle) << "MR_777" << setcolour(TEAL, chandle) << " , THE Creator of this Little Program :)" << endl;
		cout << setcolour(TEAL, chandle) << "- If you find any BUGS or Mistakes, Then tell me on my WhatsApp:    " << setcolour(YELLOW, chandle) << "+92 314 5401405" << endl;
		cout << setcolour(TEAL, chandle) << "- I`ve Created some Guides, You may like `em:  " << setcolour(YELLOW, chandle) << "bit.ly/H4ck3R_777" << setcolour(GREEN, chandle) << "  or  " << setcolour(YELLOW, chandle) << "bit.ly/MR_777" << endl;
		cout << setcolour(WHITE, chandle) << "\n  Thank You 4 Using my Script!\n" << endl;
		cout << setcolour(WHITE, chandle);

		cout << endl;
		system("pause");
		system("cls");
	}

	void COVID_19()
	{
		HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << setcolour(RED, chandle);
		cout << "      +-------------------------------------------------------------------------------+" << endl;
		cout << "      |                           May ALLAH Save us from                              |" << endl;
		cout << "      +-------------------------------------------------------------------------------+" << endl;
		cout << "      |                                                                               |" << endl;
		cout << "      |  .d8888b.   .d88888b.  888     888 8888888 8888888b.        d888   .d8888b.   | " << endl;
		cout << "      | d88P  Y88b d88P\" \"Y88b 888     888   888   888  \"Y88b      d8888  d88P  Y88b  | " << endl;
		cout << "      | 888    888 888     888 888     888   888   888    888        888  888    888  | " << endl;
		cout << "      | 888        888     888 Y88b   d88P   888   888    888        888  Y88b. d888  | " << endl;
		cout << "      | 888        888     888  Y88b d88P    888   888    888        888   \"Y888P888  | " << endl;
		cout << "      | 888    888 888     888   Y88o88P     888   888    888 888888 888         888  | " << endl;
		cout << "      | Y88b  d88P Y88b. .d88P    Y888P      888   888  .d88P        888  Y88b  d88P  | " << endl;
		cout << "      |  \"Y8888P\"   \"Y88888P\"      Y8P     8888888 8888888P\"       8888888 \"Y8888P\"   | " << endl;
		cout << "      |                                                                               |" << endl;
		cout << "      +-------------------------------------------------------------------------------+" << endl;
		cout << "\n" << endl;
		cout << setcolour(GREEN, chandle);
		cout << " - Track COVID-19 Details here : " << setcolour(BLUE, chandle) << "bing.com/covid" << setcolour(GREEN, chandle) << endl;
		cout << " - Watch the Documentary on COVID-19 here : " << setcolour(BLUE, chandle) << "https://www.youtube.com/watch?v=I-Yd-_XIWJg" << setcolour(GREEN, chandle) << endl;
		cout << " - I know the reason Y you entered such INPUT, so that, I've created this little message" << endl;
		cout << " - There's no need to worry about, we had 4 Major Epidemics in past 400yrs." << endl;
		cout << " - All are gone now, but the there is new thing here," << endl;
		cout << " - Due to connectivity of the whole world, it's everywhere now" << endl;
		cout << " - So, sad to say, no one is safe now." << endl;
		cout << " - ALLAH said, \"To every desease, there is a cure!\"" << endl;
		cout << " - If U R reading this message, Pray for all MUSLIMS of the world!" << endl;
		cout << " - With best wishes, Good Luck! and Be Safe!" << endl;
		cout << "\n" << endl;
		cout << setcolour(WHITE, chandle);

		cout << " By The Way, besides all that, Thank U 4 using my Little Program!" << endl;
		cout << endl;
		system("pause");
		system("cls");
	}
}

namespace get
{
	void getline1(std::istream& in, std::string& word, char delim = '\n')
	{
		char ch;
		word = "";
		while (in.get(ch)) {
			word += ch;
			if (ch == delim)
				break;
		}
	}

	void getline2(std::istream& in, std::string& word, char delim = '\n')
	{
		char ch;

		do
		{
			in.get(ch);
			word += ch;
		} while (ch != delim);
	}
}

















int main()
{
	// Window Resize:

		system("mode 100,40");   //Set mode to ensure window does not exceed buffer size
		SMALL_RECT WinRect = { 0, 0, 100, 40 };   //New dimensions for window in 8x12 pixel chars
		SMALL_RECT* WinSize = &WinRect;
		SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

	// Initialization

		string s_choice;
		int choice;
		system("title MR_777");

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
		cout << " | These are my Some of the Biggest Projects, I ever started,  |" << endl;
		cout << " | in C++. I Just Combined all of them in one Single Project.  |" << endl;
		cout << " | There are some Unique Inputs, which U can use to watch my   |" << endl;
		cout << " | secret messages. Try to find those unique Inputs            |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << endl;



		cout << setcolour(GREEN, chandle);
		cout << endl;
		cout << " - Choose Operation." << endl;
		cout << " ====================" << endl;
		cout << endl;

		MAIN:

		cout << setcolour(WHITE, chandle);
		cout << setcolour(BLUE, chandle) << "1" << setcolour(WHITE, chandle) << ". | EasyLoad Calculator" << endl;
		cout << setcolour(BLUE, chandle) << "2" << setcolour(WHITE, chandle) << ". | Values Extraction from a String" << endl;
		cout << setcolour(BLUE, chandle) << "3" << setcolour(WHITE, chandle) << ". | Guessing Game v2" << endl;
		cout << endl;
		cout << setcolour(GREEN, chandle) << "- Your Choice : " << setcolour(BLUE, chandle);
		getline(cin , s_choice);
		cin.clear();
		cin.sync();

		stringstream(s_choice) >> choice;


	// Decision Making & Redirection

		system("cls");
		cout << setcolour(WHITE, chandle);
		if (choice != 0)
		{
			switch (choice)
			{
				case 1:
				{
					MAIN::EasyLoad();
					break;
				}

				case 2:
				{
					MAIN::Extractor();
					break;
				}

				case 3:
				{
					MAIN::Guess_Game_start();
					break;
				}

				case 777:
				{
					Secrets::SecretMSG();
					break;
				}

				case 19:
				{
					Secrets::COVID_19();
					break;
				}

				default:
				{
					cout << setcolour(RED, chandle) << "Invalid Input!" << endl;
					break;
				}
			}
		}
		else
		{
			if (s_choice == "0")
			{
				cout << "Why XERO Input ???" << endl;

				cout << endl;
				system("pause");
			}
			else if (s_choice == "MR_777" || s_choice == "mr_777" || s_choice == "MR" || s_choice == "mr")
			{
				Secrets::SecretMSG();
			}
			else if (s_choice == "COVID" || s_choice == "covid" || s_choice == "COVID-19" || s_choice == "covid-19" || s_choice == "COVID19" || s_choice == "covid19" || s_choice == "corona" || s_choice == "Corona" || s_choice == "CORONA")
			{
				Secrets::COVID_19();
			}
			else if (s_choice == "Elsa Grey" || s_choice == "ElsaGrey" || s_choice == "elsa grey" || s_choice == "elsagrey" || s_choice == "Elsa grey" || s_choice == "Elsagrey")
			{
				cout << "Elsa Grey, The Great Future Programmer!" << endl;
				cout << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << setcolour(RED, chandle) << "!!!... Invalid Input ...!!!" << endl;
			}
		}

			

	// Final Message will come 1st

		cout << setcolour(GREEN, chandle);
		cout << "\n" << endl;
		cout << "----------------------------------------" << endl;
		cout << ">-    Script Created by  ./" << setcolour(DARKGREEN, chandle) << "MR_777     -<" << endl;
		cout << ">--    ThanX 4 using my Script!      --<" << endl;
		cout << ">---     Press Ctrl+C to Exit       ---<" << endl;
		cout << "========================================\n" << endl;
		cout << setcolour(WHITE, chandle);

	// Recursive

		goto MAIN;
}
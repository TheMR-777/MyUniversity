#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>
#include <cmath>
#include <vector>
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

/*
namespace INPUT
{
    template<typename ANY>
}

namespace OUTPUT
{
    template<typename ANY>
}
*/

void intro()
{
    cout << "----------------------------------------" << endl;
	cout << ">-    Script Created by  ./MR_777     -<" << endl;
	cout << ">--    ThanX 4 using my Script!      --<" << endl;
	cout << ">---     Press Ctrl+C to Exit       ---<" << endl;
	cout << "========================================" << endl;
}

void Easy_load
{
    HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
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
    }
}

void decision(const string &choice)
{
    switch(choice)
    {
        case 1:
        {
            
        }
    }
}



int main()
{
    // Color Placement

        HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
        
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
	
	// Initialization

        string choice;
    
    // Main Menu

        MAIN_MENU:

        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " | It's MR_777 's Program                                      |" << endl;
        cout << " | Select any of the Option below                              |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << endl;

        cout << " 1. Easyload Calculator" << endl;

        cout << endl;
        cout << "- Your Choice : ";
        cin >> choice;

    // Decision Making


}
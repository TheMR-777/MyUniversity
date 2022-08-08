#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

unsigned short rand_time()
{
    srand(time(NULL));
    return (rand() % 6) + 2;
}

unsigned short rand_CPU()
{
    srand(clock());
    return (rand() % 6) + 2;
}

unsigned short rand_time_CPU()
{
    srand( ( time(NULL) + clock() ) * 777 );
    return (rand() % 6) + 2;
}

void play_game( unsigned int &chips , string &backup )
{
    
    
    // Introduction

        system("cls");
        cout << endl;
        cout << " +-----------------------------------------------------------+" << endl;
        cout << " | Here's the brief Guide. Follow the instructions below, &  |" << endl;
        cout << " | three Random Numbers will be Generated, according to the  |" << endl;
        cout << " | TIME Standard and CPU Clock Time. Probability of Random   |" << endl;
        cout << " | number is very high. Your bet will be ...                 |" << endl;
        cout << " |                                                           |" << endl;
        cout << " | - [ 10x ] If all Numbers are \"7\"                          |" << endl;
        cout << " | - [ 05x ] If all Numbers are Identical                    |" << endl;
        cout << " | - [ 03x ] If two Numbers are Identical                    |" << endl;
        cout << " | - [ 000 ] If all Numbers are Different                    |" << endl;
        cout << " +-----------------------------------------------------------+" << endl;
        cout << endl;

    // Starting Bet

        system("pause");
        cout << endl;

    // Random Numbers Generation

        unsigned short R1 = rand_time();
        unsigned short R2 = rand_CPU();
        unsigned short R3 = rand_time_CPU();

    // Output

        cout << " +-----------------------------------------------------------+" << endl;
        cout << " |  Slot #1 " << "\t\t" << " Slot #2 " << "\t\t" << " Slot #3     |" << endl;
        cout << " +-----------------------------------------------------------+" << endl;
        cout << " |     " << R1 << "                    " << R2 << "                       " << R3 << "        |" << endl;
        cout << " +-----------------------------------------------------------+" << endl;
        cout << endl;

    // Outputting what happened

        if ( R1 == R2 && R2 == R3 )
        {
            if ( R1 == 7 && R2 == 7 && R3 == 7 )
            {
                chips *= 10;

                cout << " - Congratulations! U got the Luckiest Luck!" << endl;
                cout << " - Your Credit is now 10x" << endl;
                cout << " - Current Credit : " << chips << endl;
            }
            else
            {
                chips *= 5;

                cout << " - Congrats! U got the Better Luck!" << endl;
                cout << " - Your Credit is now 5x" << endl;
                cout << " - Current Credit : " << chips << endl;
            }
        }
        else if ( R1 == R2 || R1 == R3 || R2 == R3 )
        {
            chips *= 3;

            cout << " - You got the Luck!" << endl;
            cout << " - Your Credit is now 3x" << endl;
            cout << " - Current Credit : " << chips << endl;
        }
        else
        {
            cout << " - Better Luck Next Time!" << endl;
            cout << " - You Lost your Credit" << endl;

            ENTER:

            chips = 0;
            cout << " - Current Credit : " << chips << endl;
            cout << " - Enter New Credit below" << endl;
            cout << " > ";
            cin >> backup;

            if ( backup[0] > '0' )
            {
                cout << "Chips Recieved Successfully!" << endl;
                stringstream(backup) >> chips;
                cout << endl;

                if ( chips == 0 )
                {
                    cout << "Such Chips are not Acceptable!" << endl;
                    cout << endl;
                    goto ENTER;
                }
            }
            else if ( backup == "0" )
            {
                cout << "0 Chips are not Acceptable!" << endl;
                cout << endl;
                goto ENTER;
            }
            
        }
        
        
}

int main()
{
    // Initialization

	    short choice;
        unsigned int chips = 2000;
        string backup;

    // Introduction
    
        MAIN:
        system("cls");
        cout << endl;
        cout << " +-----------------------------------------------------------+" << endl;
        cout << " | It's a Slot Machine, which will award u according to your |" << endl;
        cout << " | luck and chance. We'll start with 2000$ Chips.            |" << endl;
        cout << " +-----------------------------------------------------------+" << endl;
        cout << endl;

	// Main Menu

        cout << " - Your current Chips : " << chips << "$" << endl;
        cout << " - Choose any of the Operation Below" << endl;
        cout << endl;

        cout << " 1. Play Slots" << endl;
        cout << " 2. Quit Slot Machine" << endl;
        cout << " 3. Credits" << endl;

        cout << endl;
        cout << " > ";
        cin >> choice;

	// Redirection

	    try
        {
            if ( choice > 0 && choice < 4 )
            {
                switch (choice)
                {
                    case 1:
                    {
                        play_game( chips , backup );
                        break;
                    }

                    case 2:
                    {
                        return 0;
                        break;
                    }

                    case 3:
                    {
                        ENTER:

                        system("cls");
                        cout << endl;
                        cout << "- Enter amount of the Credit below" << endl;
                        cout << " > ";
                        cin >> backup;
                        cout << endl;

                        
                        if ( backup[0] > '0' )
                        {
                            cout << "Chips Recieved Successfully!" << endl;
                            stringstream(backup) >> chips;
                            cout << endl;

                            if ( chips == 0 )
                            {
                                cout << "Such Chips are not Acceptable!" << endl;
                                cout << endl;
                                goto ENTER;
                            }
                        }
                        else if ( backup == "0" )
                        {
                            cout << "0 Chips are not Acceptable!" << endl;
                            cout << endl;
                            goto ENTER;
                        }

                        break;
                    }
                }
            }
            else
            {
                throw choice;
            }
        }
        catch(...)
        {
            cout << "Invalid Input Detected!" << endl;
            cout << endl;
            system("pause");
        }

    // Recursive

        cout << endl;
        system("pause");
        goto MAIN;
        
        
}
#include <iostream>
using namespace std;

struct Make
{
    bool upper;
    bool lower;
    bool integer;
};


void check(const string &password , Make &password_has )
{

    for ( int i=0 ; i < password.size() ; i++ )
    {
        // Integer Detection

            if ( password[i] >= '0' && password[i] <= '9' && password_has.integer == 0 )
            {
                password_has.integer = 1;
            }

        // Lower-case Alphabet Detection

            if ( password[i] >= 'a' && password[i] <= 'z' && password_has.lower == 0 )
            {
                password_has.lower = 1;
            }

        // Upper-case Alphabet Detection

            if ( password[i] >= 'A' && password[i] <= 'Z' && password_has.upper == 0 )
            {
                password_has.upper = 1;
            }
    }
}


int main()
{
    // Initialization

        string password;
        Make password_has;

    // Introduction

        system("cls");
        cout << endl;
        cout << " +-------------------------------------------------+" << endl;
        cout << " | It's a Password detector Program. It'll open a  |" << endl;
        cout << " | specific file for u, when u enter a right pass- |" << endl;
        cout << " | word. Enter the Secret Code to change Password  |" << endl;
        cout << " +-------------------------------------------------+" << endl;
        cout << " | But currently, it's just a Test Program, to     |" << endl;
        cout << " | TEST a Password, that user will Enter. It can   |" << endl;
        cout << " | be Modified with some Replacements of if-else`s |" << endl;
        cout << " +-------------------------------------------------+" << endl;
        cout << endl;

    // Taking Input

        cout << "- Enter the Password below" << endl;
        cout << ">  ";
        getline( cin , password );

    // Redirection

        cout << endl;

        if ( password.size() < 8 )
        {
            cout << "Your Password must have at least 8 Characters!" << endl;
        }
        else
        {
            check( password , password_has );
            
            if ( password_has.integer == 0 || password_has.lower == 0 || password_has.upper == 0 )
            {
                if ( password_has.integer == 0 )
                {
                    cout << "Integer not found in your Password!" << endl;
                }
                if ( password_has.lower == 0 )
                {
                    cout << "Lower_Case Character not found in your Password!" << endl;
                }
                if ( password_has.upper == 0 )
                {
                    cout << "Upper_Case Character not found in your Password!" << endl;
                }
            }
            else
            {
                // File opening here

                cout << "Success!" << endl;
            }  
        }

        

    // Finalization

        cout << endl; 
        system("pause");
        cin.clear();
        cin.sync();
        main();
}
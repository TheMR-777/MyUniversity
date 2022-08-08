#include <iostream> 
using namespace std;

void sort(string &S , bool op)
{
    char temp;
    for ( int i=0 ; i < (S.size() - 1) ; i++ )
    {
        for ( int j=(i+1) ; j < S.size() ; j++ )
        {
            if( op == 0 )
            {
                if ( S[j] < S[i] )
                {
                    temp = S[j];
                    S[j] = S[i];
                    S[i] = temp;
                }
            }
            else
            {
                if ( S[j] > S[i] )
                {
                    temp = S[j];
                    S[j] = S[i];
                    S[i] = temp;
                }
            }
        }
    }
}



int main()
{
    // Initialization

        string S;
        bool c;

    // All Code Below

        system("cls");
        cout << endl;
        cout << " +------------------------------------------------------+" << endl;
        cout << " | It's a Simple String Sorter, which eill sort the     |" << endl;
        cout << " | indivisual characters of the string Alphabatically   |" << endl;
        cout << " +------------------------------------------------------+" << endl;
        cout << " | - Enter any String below ...                         |" << endl;
        cout << " |                                                      |" << endl;
        cout << " | > "; getline(cin , S);
        cout << " |                                                      |" << endl;
        cout << " |------------------------------------------------------|" << endl;
        cout << " | - In which way u wanna sort the String?              |" << endl;
        cout << " | 0. Ascending              1. Descending              |" << endl;
        cout << " |                                                      |" << endl;
        cout << " | > "; cin >> c;
        cout << " |                                                      |" << endl;
        cout << " |------------------------------------------------------|" << endl;
        cout << " | The String in ";

        if (c == 0)
        {
            cout << "ASCENDING ";
        }
        else
        {
            cout << "DESCENDING";
        }
        sort (S , c);

        cout <<                            " order is ...                |" << endl;
        cout << " |                                                      |" << endl;
        cout << " | - " << S << endl;
        cout << " |                                                      |" << endl;
        cout << " +------------------------------------------------------+" << endl;
        cout << " | - " ; system("pause");
}
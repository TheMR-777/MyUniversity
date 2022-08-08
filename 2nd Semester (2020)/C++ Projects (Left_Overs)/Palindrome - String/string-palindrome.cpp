#include <iostream> 
using namespace std;

// The following Templatized Function can Reverse any String, Vector, or STL Array
// Integers, and Normal Arrays are not supported by following Templatized Function

template<typename T>
T reverser(T &S)
{
    T temp;
    for ( int i=(S.size() - 1) ; i >= 0 ; i-- )
    {
        temp.push_back(S[i]);
    }

    return temp;
}

void decision(string &S)
{
    if (S == reverser(S))
    {
        cout << "PALINDROME                 |";
    }
    else
    {
        cout << "not PALINDROME             |";
    }
    
}

int main()
{
    // Initialization

        string S;

    // Introduction

        system("cls");
        cout << endl;
        cout << " +--------------------------------------------------+" << endl;
        cout << " |   It's a Palindrome Indentifier, using STRINGS   |" << endl;
        cout << " +--------------------------------------------------+" << endl;
        cout << " | - Enter any String Below ...                     |" << endl;
        cout << " |                                                  |" << endl;
        cout << " | > "; getline(cin , S);
        cout << " |                                                  |" << endl;
        cout << " | The Entered String is "; decision(S); cout << endl;
        cout << " +--------------------------------------------------+" << endl;
        cout << " | - "; system ("pause");
        main();
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialization

        vector< vector<int> > Matrix = 
        {
            { 1 , 2 , 3 , 99 },
            { 4 , 5 , 6 , 99 },
            { 7 , 8 , 9 , 99 }
        };

    // Outputting Elements 

        system("cls");
        cout << "Members: \n" << endl;
        
        for (int col=0 ; col < Matrix.size() ; col++ )
        {
            for ( int row=0 ; row < Matrix[col].size() ; row++)
            {
                cout << Matrix[col][row] << "\t";
            }
            cout << endl;
        }
        cout << endl;

    // Size

        cout << "Rows : \t\t" << Matrix[0].size() << endl; 
        cout << "Coloumns : \t" << Matrix.size() << endl;
}
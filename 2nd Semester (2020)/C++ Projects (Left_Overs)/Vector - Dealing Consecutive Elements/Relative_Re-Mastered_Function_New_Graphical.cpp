#include <iostream>
#include <vector>
using namespace std;


// Function Parameter Guide:
// calc( Element of the Vector #1 , Element of the Vector #2 , Operation on those Elements )


int calc(int x , int y , int op)
{
    switch(op)
    {
        case 1:
        {
            return (x+y);
        }

        case 2:
        {
            if (x > y)
            {
                return (x-y);
            }
            else
            {
                return (y-x);
            }
        }

        case 3:
        {
            return (x * y);
        }
    }
}


int main()
{
    // Initialization

        vector<int> A;
        vector<int> B;
        int size, temp;


    // Introduction

        system("cls");
        cout << " +--------------------------------------------------------------+" << endl;
        cout << " |             It's the Relative Elements Dealer                |" << endl;
        cout << " |       Enter Elements of the Vectors as asked below           |" << endl;
        cout << " |           But 1st, tell the SIZE of the Vectors              |" << endl;
        cout << " +--------------------------------------------------------------+" << endl;


    // Input of Size

        cout << endl;
        cout << "Enter the \"SIZE\" of the Vector: ";
        cin >> size;


    // 1st Vector Filling

        system("cls");
        cout << endl;
        cout << " +--------------------------------------------------------------+" << endl;
        cout << " |" << endl;
        for ( int i = 0 ; i < size ; i++ )
        {
            cout << " | - Enter Element \"#" << i+1 << "\" of 1st Vector : \t";
            cin >> temp;
            A.push_back(temp);
        }
        cout << " |" << endl;
        cout << " |--------------------------------------------------------------|" << endl;
        cout << " | Elements of \"1st Vector\" Recieved Successfully!" << endl;
        cout << " +--------------------------------------------------------------+" << endl;
        cout << endl;
        system("pause");


    // 2nd Vector Filling

        system("cls");
        cout << endl;
        cout << " +--------------------------------------------------------------+" << endl;
        cout << " |" << endl;
        for ( int i = 0 ; i < size ; i++ )
        {
            cout << " | - Enter Element \"#" << i+1 << "\" of 2nd Vector : \t";
            cin >> temp;
            B.push_back(temp);
        }
        cout << " |" << endl;
        cout << " |--------------------------------------------------------------|" << endl;
        cout << " | Elements of \"2nd Vector\" Recieved Successfully!" << endl;
        cout << " +--------------------------------------------------------------+" << endl;
        cout << endl;
        system("pause");


    // Outputting Relative Sum

        system("cls");
        cout << endl;
        cout << " +----------------------------------------------------------------------------------+" << endl;
        cout << " |" << endl;
        for ( int i = 0 ; i < size ; i++ )
        {
            cout << " | The \"Sum\" of Relative Element \"#" << i+1 << "\" of two Vectors is: \t[\t" << calc(A[i] , B[i] , 1) << "\t]" << endl;
        }
        cout << " |" << endl;
        cout << " +----------------------------------------------------------------------------------+" << endl;

        system("pause");


    // Outputting Relative Difference

        system("cls");
        cout << endl;
        cout << " +----------------------------------------------------------------------------------------+" << endl;
        cout << " |" << endl;
        for ( int i = 0 ; i < size ; i++ )
        {
            cout << " | The \"Difference\" of Relative Element \"#" << i+1 << "\" of two Vectors is: \t[\t" << calc(A[i] , B[i] , 2) << "\t]" << endl;
        }
        cout << " |" << endl;
        cout << " +----------------------------------------------------------------------------------------+" << endl;

        system("pause");


    // Outputting Product

        system("cls");
        cout << endl;
        cout << " +----------------------------------------------------------------------------------+" << endl;
        cout << " |" << endl;
        for ( int i = 0 ; i < size ; i++ )
        {
            cout << " | The \"Product\" of Relative Element \"#" << i+1 << "\" of two Vectors is: \t[\t" << calc(A[i] , B[i] , 3) << "\t]" << endl;
        }
        cout << " |" << endl;
        cout << " +----------------------------------------------------------------------------------+" << endl;

        system("pause");


    // For Recursive Program

        main(); 
}
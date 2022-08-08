#include <iostream>
#include <vector>
using namespace std;


// Parameter Guide:


vector<int> calc(vector<int> &A , vector<int> &B , int op)
{
    vector<int> R(A.size());

    switch(op)
    {
        case 1:
        {
            for (int i=0 ; i < A.size() ; i++)
            {
                R[i] = A[i] + B[i];
            }
        }

        case 2:
        {
            for (int i=0 ; i < A.size() ; i++)
            {
                if (A[i] > B[i])
                {
                    R[i] = A[i] - B[i];
                }
                else
                {
                    R[i] = B[i] - A[i];
                }
            }
        }

        case 3:
        {
            for (int i=0 ; i < A.size() ; i++)
            {
                R[i] = A[i] * B[i];
            }
        }
    } 

    return R;
}


void program()
{
    // Initialization

        vector<int> A;
        vector<int> B;
        vector<int> R;
        int size, var;
    

    // Intro
    
        system("cls");
        cout << endl;
        cout << "It's the Relative Element Dealer." << endl;
        cout << "Enter the Elements of two Vectors as asked." << endl;
        cout << endl;


    // Input

        cout << "Enter Size of the Vectors: ";
        cin >> size;

        system("cls");
        cout << endl;
        for ( int i=0 ; i < size ; i++ )
        {
            cout << "Enter Element #" << i+1 << " of 1st Vector : ";
            cin >> var;
            A.push_back(var);
        }

        cout << endl;
        for ( int i=0 ; i < size ; i++ )
        {
            cout << "Enter Element #" << i+1 << " of 2nd Vector : ";
            cin >> var;
            B.push_back(var);
        }


    // Generating Results

    // SUM
        
        cout << endl;
        R.clear();
        R.shrink_to_fit();
        R = calc(A , B , 1);
        for (int i=0 ; i<R.size() ; i++)
        {
            cout << "The SUM of Element #" << i+1 << "of 2 Vectors: " << R[i] << endl;
        }

        cout << endl;
        system("pause");

    // Difference

        cout << endl;
        R.clear();
        R.shrink_to_fit();
        R = calc(A , B , 2);
        for (int i=0 ; i<R.size() ; i++)
        {
            cout << "The Difference of Element #" << i+1 << "of 2 Vectors: " << R[i] << endl;
        }

        cout << endl;
        system("pause");

    // Product

        cout << endl;
        R.clear();
        R.shrink_to_fit();
        R = calc(A , B , 3);
        for (int i=0 ; i<R.size() ; i++)
        {
            cout << "The Product of Element #" << i+1 << "of 2 Vectors: " << R[i] << endl;
        }

        cout << endl;
        system("pause");
}

int main()
{
    do
    {
        program();
    }
    while (true);
}
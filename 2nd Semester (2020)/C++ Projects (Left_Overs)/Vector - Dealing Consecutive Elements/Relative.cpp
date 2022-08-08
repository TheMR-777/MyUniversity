#include <iostream>
#include <vector>
using namespace std;


// Parameter Guide:
// system(Resultant Vector ; 1st Vector ; 2nd Vector ; Operation on 2 Vectors)


void calc(vector<int> &R , vector<int> &A , vector<int> &B , int op)
{
    switch(op)
    {
        case 1:
        {
            R.clear();
            R.shrink_to_fit();
            for (int i=0 ; i < A.size() ; i++)
            {
                R.push_back(A[i] + B[i]);
            }
        }

        case 2:
        {
            R.clear();
            R.shrink_to_fit();
            for (int i=0 ; i < A.size() ; i++)
            {
                if (A[i] > B[i])
                {
                    R.push_back(A[i] - B[i]);
                }
                else
                {
                    R.push_back(B[i] - A[i]);
                }
            }
        }

        case 3:
        {
            R.clear();
            R.shrink_to_fit();
            for (int i=0 ; i < A.size() ; i++)
            {
                R.push_back(A[i] * B[i]);
            }
        }
    }
}



int main()
{
    // Initialization

        vector<int> V1, V2;
        vector<int> V_R;
        int size, temp=1;

    // Getting Things Ready

        system("cls");
        cout << endl;
        cout << "It's a Program which will Calculate, and Display the SUM, Difference and Product of Relative Elements of 2 Vectors." << endl;
        cout << "\n- Enter Size of Each Vector: ";
        cin >> size;

    // Taking Input

        system("cls");
        cout << endl;
        cout << "Okay, Now, Enter the Elements 1-by-1 of 1st Vector" << endl;
        cout << endl;

        for ( int i=0 ; i<size ; i++ )
        {
            cout << "Enter Element #" << i+1 << " of 1st Vector : ";
            cin >> temp;
            V1.push_back(temp);
        }
        cout << "Elements of 1st Vector are Successfully Recieved." << endl;

        system("pause");
        system("cls");

        cout << "Enter the Elements 1-by-1 of 2nd Vector" << endl;
        cout << endl;

        for ( int i=0 ; i<size ; i++ )
        {
            cout << "Enter Element #" << i+1 << " of 2nd Vector : ";
            cin >> temp;
            V2.push_back(temp);
        }
        cout << "Elements of 2nd Vector are Successfully Recieved." << endl;

    // Results Generation

        cout << "The SUM of Relative Elements of 2 Vectors is: ";
        cout << endl;

    // SUM of Relative Elements

        calc(V_R , V1 , V2 , 1);
        for ( int i=0 ; i < size ; i++ )
        {
            cout << "SUM of Relative Element# " << i+1 << " of 1st Vector is: " << V_R[i] << endl;
        }
        cout << endl;
        system("pause");

    // Difference of Relative Elements

        V_R.clear();
        V_R.shrink_to_fit();
        calc(V_R , V1 , V2 , 2);
        for ( int i=0 ; i < size ; i++ )
        {
            cout << "Difference of Relative Element# " << i+1 << " of 1st Vector is: " << V_R[i] << endl;
        }
        cout << endl;
        system("pause");

    // Product of Relative Elements

        V_R.clear();
        V_R.shrink_to_fit();
        calc(V_R , V1 , V2 , 3);
        for ( int i=0 ; i < size ; i++ )
        {
            cout << "Product of Relative Element# " << i+1 << " of 1st Vector is: " << V_R[i] << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
}

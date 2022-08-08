#include <iostream>
#include <vector>
using namespace std;

namespace INPUT
{
    void V_IN( vector<int> &V )
    {
        int temp=1;

        for ( int i=0 ; temp != 0 ; i++ )
        {
            cout << " Enter Element #" << i+1 << " : ";
            cin >> temp;

            if (temp != 0)
            {
                V.push_back(temp);
            }
        }
    }
}

namespace OUTPUT
{
    int SUM( vector<int> &V )
    {
        int sum = 0;

        for ( int n : V )
        {
            sum = sum + n;
        }

        return sum;
    }

    int AVG( vector<int> &V )
    {
        int sum = 0;

        for ( int n : V )
        {
            sum = sum + n;
        }

        return sum/V.size();
    }

    int PRO( vector<int> &V )
    {
        int pro = 1;

        for ( int n : V )
        {
            pro = pro * n;
        }

        return pro;
    }
}




int main()
{
    // Initialization

        vector<int> V;

    // Introduction

        system("cls");
        cout << endl;
        cout << " Enter Elements of the Vector as asked, and enter 0 when finished entering values" << endl;
        cout << endl;

    // Input

        INPUT::V_IN(V);

    // Output

        system("cls");
        cout << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "The SUM of all Elements is : "  << OUTPUT::SUM(V) << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "The Avg of all Elements is : " << OUTPUT::AVG(V) << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "The Product of all Elements is : " << OUTPUT::PRO(V) << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << endl;
        system("pause");

    // Recursive

        main();
}
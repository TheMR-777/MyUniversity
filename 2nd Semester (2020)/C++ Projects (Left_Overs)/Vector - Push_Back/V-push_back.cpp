#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // I am Using "do-while" for Continous Program
    
    do
    {
        // To avoid Messed Up Environment

            system("cls");
        

        // Introduction
        
            cout << endl;
            cout << "It's Vector Addition by using Concept of Dynamic Vector" << endl;
            cout << "Enter the Values 1-by-1, and enter \"0\" when Finished Entering values." << endl;
            cout << endl;


        // Initialization

            vector<int> V;
            int temp=1;
            int sum=0;


        // Input Using "While Loop". Un comment the lines to Test the Code
        // While Loop is less Recommended, because it has less flexibility while dealing with a Specific Element of a Vector (i.e. V[i])
        // U can tweak the while loop, as u want.
        // But Remember to Comment the "For Loop" if "while" is uncommented

        /*
            while (temp != 0)
            {
                cout << "Enter Some Value : ";
                cin >> temp;
                V.push_back(temp);
            }
        */


        // Input Using "For Loop", but with a unique Condition

            for (int i=0 ; temp != 0 ; i++)
            {
                cout << "Enter Value #" << i+1 << " : ";
                cin >> temp;

                if (temp != 0)
                {
                    V.push_back(temp);
                    sum = sum + V[i];
                }
            }


        // Outputting Sum

            cout << "\n- The Sum of Entered Quantities is: " << sum << endl;
            cout << endl;
            system("pause");

        // Finished!

    } while (true);
}
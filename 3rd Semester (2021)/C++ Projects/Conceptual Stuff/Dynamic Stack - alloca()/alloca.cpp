#include <iostream>
using namespace std;

int main()
{
    // Initialization

        int size; int* dyn_array;
        system("cls");
        cout << endl;


    // Taking required Size

        cout << " + - - - - - - - - - - - - - - - - - - - - - - - +" << endl;
        cout << " | Enter array size : ";
        cin >> size;
        cout << " |" << endl;

        dyn_array = (int*)alloca(size * sizeof(int));


    // Taking Input

        for(int i = 0; i < size; i++)
        {
            cout << " | Enter Element #" << i + 1 << " : ";
            cin >> dyn_array[i];
        }
        cout << " |" << endl;


    // The Output

        for(int i = 0; i < size; i++)
        {
            cout << " | Element #" << i + 1 << " is : " << dyn_array[i] << endl;
        }
        
        cout << " + - - - - - - - - - - - - - - - - - - - - - - - +" << endl;
}
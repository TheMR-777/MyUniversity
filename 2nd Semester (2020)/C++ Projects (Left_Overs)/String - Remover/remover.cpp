#include <iostream>
using namespace std;

int main()
{
    // Initialization

        string S;
        char R;
        bool flag=0;

    // Input
        cout << endl;
        cout << "Enter the String below ..." << endl;
        cout << "Input : ";
        getline(cin, S);
        cout << endl;

        cout << "Which Letter U wanna Remove? : ";
        cin >> R;
        cout << endl;

        cout << "Your Final String" << endl;
        cout << "Output : ";

        for (int i=0 ; i < S.size() ; i++)
        {
            if ( S[i] != R )
            {
                cout << S[i];
            }
            else
            {
                if ( flag == 0 )
                {
                    flag = 1;
                }
                else
                {
                    cout << S[i];
                }
            }
            
        }
}
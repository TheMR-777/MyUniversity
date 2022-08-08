#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    // Initialization
    
        string stg, prop;
        stringstream sss;
        vector<int> value;
        int I;

    // Taking Input

        system("cls");
        cout << " Enter any String Below." << endl;
        cout << "Input : ";
        getline(cin, stg);

    // Value Extraction Process

        for ( int i=0 ; i < stg.size() ; i++ )
        {
            if ( stg[i] >= '0' && stg[i] <= '9' )
            {
                while ( stg[i] >= '0' && stg[i] <= '9')
                {
                    prop = prop + stg[i];
                    i++;
                }
                sss << prop;
                sss >> I;
                sss = stringstream();
                value.push_back(I);
                prop = "";
            }
        }

    // Output

        for ( int i=0 ; i < value.size() ; i++)
        {
            cout << "Value #" << i+1 << " : " << value[i] << endl;
        }

    // Recursive

        cout << endl;
        system("pause");
        main();
}
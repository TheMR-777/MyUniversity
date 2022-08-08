#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> VE(const string &stg)
{
    string prop;
    stringstream sss;
    vector<int> value;
    int I;
    
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
            value.push_back(I);
            prop = "";
            sss = stringstream();
        }
    }

    return value;
}

int main()
{
    // Initialization
    
        string stg;
        vector<int> value;

    // Taking Input

        system("cls");
        cout << endl;
        cout << " Enter any String Below." << endl;
        cout << "- Input : ";
        getline(cin, stg);
        cout << endl;

    // Value Extraction Process

        value = VE(stg);

    // Output

        if (value.empty())
        {
            cout << "No Integer Value Present" << endl;
        }
        else
        {
            for ( int i=0 ; i < value.size() ; i++)
            {
                cout << "Value #" << i+1 << " : " << value[i] << endl;
            }
        }
        

    // Recursive

        cout << endl;
        system("pause");
        main();
}
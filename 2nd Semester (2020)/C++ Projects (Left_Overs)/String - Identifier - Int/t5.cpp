#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string stg, prop;
    stringstream sss;
    vector<string> S;
    int I;

    stg = "1050 TI x64";

    for ( int i=0 ; i < stg.size() ; i++ )
    {
        if ( stg[i] >= '0' && stg[i] <= '9' )
        {
            while ( stg[i] >= '0' && stg[i] <= '9')
            {
                prop = prop + stg[i];
                i++;
            }
            S.push_back(prop);
            prop = "";
        }
    }

    for ( int i=0 ; i < S.size() ; i++ )
    {
        cout << S[i] << endl;
    }
}
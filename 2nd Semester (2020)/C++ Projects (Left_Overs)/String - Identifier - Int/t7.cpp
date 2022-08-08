#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<int> values_extract(string stg)
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
            sss = stringstream();
            prop = "";
        }
    }

    return value;
}

int main()
{
    vector<int> V;
    string stg;
    cout << " Enter any String below:" << endl;
    cin >> stg;

    V = values_extract(stg);

    for ( int i : V)
    {
        cout << V[i] << endl;
    }
}
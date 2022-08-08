#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string stg, prop;
    vector<string> S;
    stringstream sss;
    vector<int> value;
    int I;

    stg = "thr45yt67uu5t";

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

    for ( int i=0 ; i < value.size() ; i++)
    {
        cout << value[i] << endl;
    }
}
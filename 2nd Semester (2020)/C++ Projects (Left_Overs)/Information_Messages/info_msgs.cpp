#include <iostream> 
#include <vector>
using namespace std;

string Msg(string s , int type)
{
    // 1 is for Information
    // 2 is for Error Message
    // 3 is for Warning Message

    switch (type)
    {
        case 1:
        {
            return ( "[Info] - " + s );
        }

        case 2:
        {
            return ( "[ERROR] - " + s );
        }

        case 3:
        {
            return ( "[Warning] - " + s );
        }
    }

    return "";
}

int main()
{
    cout << Msg("Program directory changed successfully!" , 1) << endl;
    cout << Msg("Program failed to compile!" , 2) << endl;
    cout << Msg("Program has unused variables!" , 3) << endl;
}
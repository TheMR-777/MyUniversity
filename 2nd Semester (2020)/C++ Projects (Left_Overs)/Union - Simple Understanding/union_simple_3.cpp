#include <iostream>
#define CLEAR cin.clear(); cin.sync()
using namespace std;


int main()
{

    // Initialization of Stuff

        system("cls");

        union
        {
            char c;
            short s;
            int i;
            long l;
            float f;
            double d;
        };

        cout << " +----------------------------------------+" << endl;
        cout << " | Union Testing" << endl;

    // Recieving INT

        cout << " |" << endl;
        cout << " | " << (char)26 << " Enter any value in INTEGER of Union" << endl;
        cout << " |" << endl;
        cout << " +--[Input]--> ";

        cin >> i; CLEAR;

        cout << " |" << endl;
        cout << " | [CHR] - " << c << endl;
        cout << " | [SHR] - " << s << endl;
        cout << " | [INT] - " << i << endl;
        cout << " | [LNG] - " << l << endl;
        cout << " | [FLT] - " << f << endl;
        cout << " | [DBL] - " << d << endl;

    // Recieving FLOAT

        cout << " |" << endl;
        cout << " | " << (char)26 << " Enter any value in FLOAT of Union" << endl;
        cout << " |" << endl;
        cout << " +--[Input]--> ";

        cin >> f; CLEAR;

        cout << " |" << endl;
        cout << " | [CHR] - " << c << endl;
        cout << " | [SHR] - " << s << endl;
        cout << " | [INT] - " << i << endl;
        cout << " | [LNG] - " << l << endl;
        cout << " | [FLT] - " << f << endl;
        cout << " | [DBL] - " << d << endl;

    // Recieving DBL

        cout << " |" << endl;
        cout << " | " << (char)26 << " Enter any value in DOUBLE of Union" << endl;
        cout << " |" << endl;
        cout << " +--[Input]--> ";

        cin >> d; CLEAR;

        cout << " |" << endl;
        cout << " | [CHR] - " << c << endl;
        cout << " | [SHR] - " << s << endl;
        cout << " | [INT] - " << i << endl;
        cout << " | [LNG] - " << l << endl;
        cout << " | [FLT] - " << f << endl;
        cout << " | [DBL] - " << d << endl;
        cout << " +----------------------------------------+" << endl;

    // Result

        cout << " | Result : Always access the Variables   |" << endl;
        cout << " | according to their DATA_TYPE Only.     |" << endl;
        cout << " +----------------------------------------+" << endl;
}
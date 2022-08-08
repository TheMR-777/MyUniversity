#include <iostream>
#include <string>
#include "math.h"
using namespace std;


unsigned long hex2dec(string hex)
{
    unsigned long result = 0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            result += (hex[i]-48)*pow(16,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            result += (hex[i]-55)*pow(16,hex.length( )-i-1);
        } else if (hex[i]>=97 && hex[i]<=102) {
            result += (hex[i]-87)*pow(16,hex.length()-i-1);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) 
{
    do
    {
		string hex_str;
	    cout << "\n- Enter Hex Value (Characters in Capital): ";
	    cin >> hex_str;
	    cout << "\n- Value in Decimal: \t" << dec << hex2dec(hex_str) << endl;
	    cout << "- Value in Octal: \t" << oct << hex2dec(hex_str) << endl;
	    system("pause");
	    cout << "\n\n\n" << endl;
	}
	while(true);
    return 0;
}

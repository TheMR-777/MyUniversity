#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
	int m1;
	cout << "\n- Hi, I'm Your Fortune Teller!" << endl;
	cout << "=======================================" << endl;
	x:
	cout << "\n- Enter Your Marks: ";
	cin >> m1;
	cout << "=======================================" << endl;
	if (m1<=100)
	{
		if (m1>=40)
		    {
		    	cout << "- Congratulations! You are Passed!" << endl;
			}
		else
			{
				cout << "- Sorry to say, You are failed!" << endl;
			}
	}
	else
	{
	cout << "- Enter Marks Between 1-100 Please." << endl;
	cout << "- Restarting ..." << endl;
	goto x;
	}
	cout << "---------------------------------------" << endl;
	cout << "- Script Created by ./MR_777 ." << endl;
	cout << "- ThanX 4 using my Script!" << endl;
	cout << "- Press Ctrl+C to Exit" << endl;
	cout << "=======================================\n" << endl;
	if (cin.get() == '\n')
	{
		goto x;
	}
	else
	exit;
	return 0;
}

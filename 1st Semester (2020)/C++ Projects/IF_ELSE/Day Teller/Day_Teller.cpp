#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
	int m1;
	cout << "\n- Hi, I'm Day Teller" << endl;
	cout << "=======================================" << endl;
	x:
	cout << "\n- Enter any Number between 1-7: ";
	cin >> m1;
	cout << "=======================================" << endl;
	if (m1==1)
	cout<<"- It's Sunday Today" << endl;
	else if (m1==2)
	cout << "- It's Monday Today" << endl;
	else if (m1==3)
	cout << "- It's Tuesday Today" << endl;
	else if (m1==4)
	cout << "- It's WednessDay Today" << endl;
	else if (m1==5)
	cout << "- It's Thursday Today" << endl;
	else if (m1==6)
	cout << "- It's Friday Today" << endl;
	else if (m1==7)
	cout << "- It's Saturday Today" << endl;
	else 
	cout << "- !...Invalid Number Entered...!" << endl;







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

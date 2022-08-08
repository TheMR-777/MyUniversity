//============================================================================
// Name        : Day_Teller_using_Switch.cpp
// Author      : ./MR_777
// Version     : 0.1 Alpha
// Copyright   : All of the content is protected under the copyrights of MR_777 . Copying or Redestribution of the following content is strictly prohibited!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	system("color B");
	int x;
	cout << "- Hi, I'm Day-Teller, who uses Switch System" << endl;
	x:
	cout << "\n- Enter any Number from 1-7 : ";
	cin >> x;

	switch (x)
	{
	case 1:
		cout << "\n- 1- Is for Monday" << endl;
		break;
	case 2:
		cout << "\n- 2- Is for Tuesday" << endl;
		break;
	case 3:
		cout << "\n- 3- Is for Wednessday" << endl;
		break;
	case 4:
		cout << "\n- 4- Is for Thursday" << endl;
		break;
	case 5:
		cout << "\n- 5- Is for Friday" << endl;
		break;
	case 6:
		cout << "\n- 6- Is for Saturday" << endl;
		break;
	case 7:
		cout << "\n- 7- Is for Sunday" << endl;
		break;
	default:
		cout << "\n- Invalid Number Entered...!!!" << endl;
		break;
	}
	goto x;
	system("pause");
	return 0;
}

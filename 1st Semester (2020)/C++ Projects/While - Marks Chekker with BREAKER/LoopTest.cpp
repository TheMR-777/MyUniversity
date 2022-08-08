#include <iostream>
using namespace std;


int main() 
{
	system("color B");
	int t=1;
	int m;
	while (t>0)
	{
		cout << "\n- Enter Your Passing Marks: ";
		cin >> m;
		if (m >= 33)
		{
			break;
		}
		cout << "You are failed, Please Enter your passing marks";
		t++;
	}
	cout << "\n- Now U R Passed! - Exiting";
}

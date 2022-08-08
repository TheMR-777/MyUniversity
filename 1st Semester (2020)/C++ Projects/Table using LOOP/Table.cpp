#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;


int main(int argc, char** argv) 
{
	system("title Table");
	system("color B");
	int n,i,l;
	cout << "- Hi, I'm Table Generator." << endl;
	x:
	cout << "=======================" << endl;
	cout << "\n- Enter Initial Number: ";
	cin >> n;
	cout << "-----------------------" << endl;
	cout << "\n- Enter Maximum Limit of Table: ";
	cin >> l;
	cout << "-----------------------" << endl;
	cout << "\n- Table of " << n << " :" << endl;
	cout << "=======================" << endl;
	i=1;
	while(i<=l)
    {
        cout << "   " << n << " x " << i << " = " << n*i << endl;
        i++;
    }
	cout << "-----------------------" << endl;
	cout << "\n- Table Finnished ...";
	cout << "\n- Press Any key to restart Script,";
	cout << "\n- Or press Ctrl+C to Exit\n";
	cout << "\n- Script Created by ./MR_777\n\n";
	goto x;
	return 777;
}

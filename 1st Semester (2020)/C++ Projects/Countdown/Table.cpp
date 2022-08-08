#include <iostream>
#include <conio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	system("color B");
	int a,m;
	x:
	cout << "\n- Enter Initial Number: ";
	cin >> a;
	while (a > 0)
	{
		cout << "\n- Countdown: " << a;
		a=a-1;
		system("timeout 1");
	}
	cout << "\n- Countdown Finnished ...";
	cout << "\n- Press Enter to restart Countdown,";
	cout << "\n- Or press Ctrl+C to Exit.\n\n";
	system("pause");
	goto x;
	return 777;
}

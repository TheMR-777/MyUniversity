#include <iostream>
using namespace std;

int main() 
{
	int a;
	char g;
	x:
	system("color 7");
	cout << "\n=========================\n";
	cout << "Enter your Gender (M/F): ";
	cin >> g;
	if (g == 'M' || g == 'F')
	{
		system("color B");
		cout << "Enter Your Age: ";
		cin >> a;
		if (g == 'M' && a > 0 && a <= 7)
		cout << "\n- You are a Child.\n";
		else if (g == 'M' && a > 7 && a < 18)
		cout << "\n- You are an Immature Boy.\n";
		else if (g == 'M' && a >= 18 && a < 40)
		cout << "\n- You are a Young Guy.\n";
		else if (g == 'M' && a >= 40 && a < 60)
		cout << "\n- You are a Mature Man.\n";
		else if (g == 'M' && a >= 60 && a < 100)
		cout << "\n- You are an Old Person.\n";
		else if (g == 'M' && a >= 100)
		cout << "\n- WoW!, I don't know, how are you ALIVE...!!!\n";
		if (g == 'F' && a > 0 && a <= 7)
		cout << "\n- You are a Child.\n";
		else if (g == 'F' && a > 0 && a < 20)
		cout << "\n- You are an Immature Girl.\n";
		else if (g == 'F' && a >= 20 && a < 40)
		cout << "\n- You are a Young Lady.\n";
		else if (g == 'F' && a >= 40 && a < 60)
		cout << "\n- You are a Mature Woman.\n";
		else if (g == 'F' && a >= 60 && a < 100)
		cout << "\n- You are an Old Woman.\n";
		else if (g == 'F' && a >= 100)
		cout << "\n- I don't know, how are you ALIVE...!!!\n";
	}
	else
	{
		cout << "\n- Invalid Character Entered" << endl;
		goto x;
	}
	goto x;
	system("pause");
	return 0;
}

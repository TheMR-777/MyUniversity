#include <iostream>
using namespace std;

int main()
{
	int a;
	char g;
x:
	system("color b");
	cout << "\n============================\n";
	cout << "\n- Enter Your Gender (M/F): ";
	cin >> g;
	if (g == 'M' || g == 'F')
	{
		cout << "\n- Enter Your Age: ";
		cin >> a;
		cout << "\n----------------------------\n";
			switch (g)
			{
			case 'M':
				{
				if (a == 0)
					cout << "\n- How's This POSSIBLE...?\n";
				else if (a > 00 && a <= 7)
					cout << "\n- You R a Child.\n";
				else if (a > 07 && a <= 18)
					cout << "\n- You R a Teenager Boy.\n";
				else if (a > 18 && a <= 30)
					cout << "\n- You R a Young Guy.\n";
				else if (a > 30 && a <= 50)
					cout << "\n- You R a Mature Man.\n";
				else if (a > 50 && a <= 75)
					cout << "\n- You R gonna be Old :)\n";
				else if (a > 75 && a <= 90)
					cout << "\n- You R an Old Man.\n";
				else if (a > 90 && a <= 100)
					cout << "\n- You R very Old Man.\n";
				else if (a > 100)
					cout << "\n- Glad to see U Alive!\n";
				else
					cout << "\n- Invalid Number Entered.\n";
				break;
				}
			case 'F':
				{
				if (a == 0)
					cout << "\n- How's This POSSIBLE...?\n";
				else if (a > 00 && a <= 7)
					cout << "\n- You R a Child.\n";
				else if (a > 07 && a <= 18)
					cout << "\n- You R a Teenager Girl.\n";
				else if (a > 18 && a <= 30)
					cout << "\n- You R a Young Lady.\n";
				else if (a > 30 && a <= 50)
					cout << "\n- You R a Mature Woman.\n";
				else if (a > 50 && a <= 75)
					cout << "\n- You R gonna be Old :)\n";
				else if (a > 75 && a <= 90)
					cout << "\n- You R an Old Woman.\n";
				else if (a > 90 && a <= 100)
					cout << "\n- You R very Old Woman.\n";
				else if (a > 100)
					cout << "\n- Glad to see U Alive!\n";
				else
					cout << "\n- Invalid Number Entered.\n";
				break;
				}
			default:
				cout << "\n- Invalid Character Entered.\n";
				break;
			}
	}
	else
	{
		cout << "\n- Invalid Character Entered.\n";
			goto x;
	}
	goto x;
	return 777;
}

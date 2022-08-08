#include <iostreaM>
using namespace std;

int main()
{
	int n;
	
	cout << "Input: ";
	cin >> n;
	
	
	
	loop:
	for (int star=0 ; star < n ; star++)
	{
		for (int space=0 ; space < (star+1) ; space++)
		{
			if (space == (star-1))
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
			
		}
		cout << endl;
	}
	
	for (int star=n ; star > 0 ; star--)
	{
		for (int space=0 ; space < (star+1) ; space++)
		{
			if (space == (star-1))
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
			
		}
		cout << endl;
	}
	goto loop;
	
	system("pause");
	system("cls");
	goto loop;
}

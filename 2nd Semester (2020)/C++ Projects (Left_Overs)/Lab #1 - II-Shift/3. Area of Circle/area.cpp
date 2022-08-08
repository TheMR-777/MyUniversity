#include<iostream>
using namespace std;

int main()
{
	do
	{
		float R;
		cout << "\n" << endl;
		cout << " +------------------------------------------+" << endl;
		cout << " | Gimme the Radius of any Circle: ";
		cin >> R;
		cout << " | ---------------------------------------- |" << endl;
		cout << " | Area of that Circle: " << (3.1417)*R*R << " sq units" << endl;
		cout << " | ---------------------------------------- |" << endl;
		cout << " |          I know that's easy :)           |" << endl;
		cout << " +------------------------------------------+" << endl;
		
		cout << "\n\n\n" << endl;
		system("pause");
	}
	while(true);
	
}

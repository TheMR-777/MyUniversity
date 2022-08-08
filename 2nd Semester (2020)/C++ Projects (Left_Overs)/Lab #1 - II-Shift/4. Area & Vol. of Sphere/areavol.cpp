#include <iostream>
using namespace std;

int main()
{
	float R;
	cout << "\n\n" << endl;
	cout << " +--------------------------------------------------+" << endl;
	cout << " | Gimme the Radius of any Sphere: ";
	cin >> R;
	cout << " |                                                  |" << endl;
	cout << " | ------------------------------------------------ |" << endl;
	cout << " | Volume of that Sphere : " << ((4*3.1417)/3)*R*R*R << "\t\t    |" << endl;
	cout << " | ------------------------------------------------ |" << endl;
	cout << " | Area of that Sphere : " << (4*3.1417)*R*R << "\t\t    |" << endl;
	cout << " +--------------------------------------------------+" << endl;
	cout << " | I know that was easy :)                          |" << endl;
	cout << " +--------------------------------------------------+" << endl;
	
	cout << "\n\n" << endl;
	system("pause");
}

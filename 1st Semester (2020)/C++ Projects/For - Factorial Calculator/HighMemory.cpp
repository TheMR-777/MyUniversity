#include <iostream>
using namespace std;


int main(int argc, char** argv) 
{
	system("color B");
	x:
	int fac = 0;
	int factorial;
	cout << "\n- Enter number: ";
	cin >> factorial;
	fac = factorial;
	
	//Loop:
	
	for (int dec = fac - 1 ; dec > 1 ; dec--)
	{
		fac = fac*dec;
	}
	cout << "\n- Factorial of " << factorial << " is = " << fac << endl;;
	goto x;
	return 777;
}

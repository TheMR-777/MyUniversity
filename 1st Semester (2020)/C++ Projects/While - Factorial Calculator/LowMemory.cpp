#include <iostream>
using namespace std;


int main(int argc, char** argv) 
{
	system("color B");
	x:
	unsigned long long int fac=0;
	cout << "\n- Enter number: ";
	cin >> fac;
	
	int dec = fac - 1 ;
	
	while (dec > 1)
	{
		fac = fac*dec;
		dec--;
	}
	cout << "\n- Factorial = " << fac << endl;;
	goto x;
	
	/*
	In Case of FOR Loop:
	====================
	
	for (int dec = fac - 1 ; dec > 1 ; dec--)
	{
		fac = fac*dec;
	}
	*/
	return 777;
}

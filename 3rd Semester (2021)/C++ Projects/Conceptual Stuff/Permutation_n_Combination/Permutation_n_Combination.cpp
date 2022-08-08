#include<iostream>
#define Log(x) cout << x << endl
using namespace std;


int fac(int fac)
{
	int dec = fac - 1;
	while (dec > 1)
	{
		fac *= dec;
		dec--;
	}

    return fac;
}

int perm(int n, int r)
{
	return fac(n) / fac(n - r);
}

int comb(int n, int r)
{
	return fac(n) / (fac(n - r) * fac(r));
}



int main()
{
	
}
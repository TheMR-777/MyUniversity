#include <iostream>
using namespace std;

int maximum(int x , int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		if(x < y)
		{
			return y;
		}
		
	}
}


int main(int argc, char** argv) 
{
	x:
	int a, b;
	
	cout << "\n- Enter 1st Number: ";
	cin >> a;
	cout << "\n- Enter 2nd Number: ";
	cin >> b;
	
	cout << "\n>=>---> Maximum Number is: " << maximum(a, b) << endl;
	
	
	
	goto x;
	return 0;
}

#include <iostream>
using namespace std;

int main() 
{
	for ( int i = 0 ; i < 10 ; i += 3 && cout << "Done" << endl)
	{
		cout << "Code Called " << i+1 << " Time - ";
	}
}
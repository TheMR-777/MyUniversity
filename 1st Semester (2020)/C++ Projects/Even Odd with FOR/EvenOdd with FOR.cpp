#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int l, o;
	EvenOdd:                             //Limit Selection
		cout << "\n-----------";
		cout << "\nEnter Limit: ";
		cin >> l;
	op:                                  //Operation Selection
		cout << "\n-----------";
		cout << "\n0-For Even";
		cout << "\n1-For Odd";
		cout << "\n-----------";
		cout << "\nEnter Operation: ";
		cin >> o;
		cout << "\n-----------\n";
	
	for(int i=1 ; i < l+1 ; i++)         //Initialization ; Condition ; Updation
	{
		if (o == 1 || o == 0)            //Checking Valid Integer
		{
			if (o == 1)                  //For ODD (as 1 is odd)
			{
				if (i%2 != 0)            //Modulation Technique for Odd Numbers
			cout << i << "\t";
			}
			if (o == 0)                  //For Even (as 0 is even)
			{
				if (i%2 == 0)            //Modulation Technique for Even Numbers
				cout << i << "\t";
			}
		}
		else                             //For Invalid Integer
		{
			cout << "\nInvalid Operation Entered!\n";
			goto op;
		}
	}
	
	goto EvenOdd;
	return 0;
}

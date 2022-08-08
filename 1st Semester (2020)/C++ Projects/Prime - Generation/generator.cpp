#include <iostream>
using namespace std;

int main()
{
	int user, flag;
	cout << "Enter the MAXIMUM Limit value : ";
	cin >> user;
	
	// Generation
	
	for (int i=1 ; i <= user ; i++)							// ---> Just Goes to USER's entered number
	{
		flag = 1;											// ---> Generates the Condition for later LATER
		
		for (int j=2 ; j <= i/2 ; j++)						// ---> Loop, designed to Compare numbers with 1st loop, MAX=i/2
		{
			if (i%j == 0)									// ---> If the number is EVEN or DIVISIBLE by any number, the condition will become true
			{
				flag = 0;									// ---> Generates the Condition that NUMBER is not PRIME
				break;										// ---> Breaks the J Loop (2nd Loop)
			}
		}
		
		if (flag == 1)										// ---> Since the number in I was prime, so it Generates that condition
		{
			cout << i << " ";								// ---> Outputs that "I" was PRIME number
		}
	}
}

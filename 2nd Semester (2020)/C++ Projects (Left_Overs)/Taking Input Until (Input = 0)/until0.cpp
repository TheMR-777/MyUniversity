#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> V;
	do
	{
		system("cls");
		V.clear();
		cout << "\n- Enter your Values 1-by-1 (Enter 0 when finished entering Values)" << endl << endl;
		
		
		// Taking Input while your Input != 0
		
		for ( int i = 0 ; i >= 0 ; i++)
		{
			int temp=0;
			cout << "Enter Value #" << i+1 << " : ";
			cin >> temp;
			
			if (temp == 0)
			{
				break;
			}
			else
			{
				V.push_back(temp);
			}
		}
	}
	while ( true );
}

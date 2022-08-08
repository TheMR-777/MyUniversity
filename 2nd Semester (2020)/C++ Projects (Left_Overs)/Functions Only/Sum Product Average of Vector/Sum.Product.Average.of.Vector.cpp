#include <iostream>
#include <vector>
using namespace std;

int calculator(vector<int> V, int op)
{
	long double temp_stg=0;
	
	switch(op)
	{
		case 1:
		case 3:
			{
				for (int i=0 ; i < V.size() ; i++)
				{
					temp_stg = temp_stg + V[i];
				}
				if (op == 3)
				{
					temp_stg = temp_stg/V.size();
				}
				break;
			}
			
		case 2:
			{
				temp_stg = 1;
				
				for (int i=0 ; i < V.size() ; i++)
				{
					temp_stg = temp_stg * V[i];
				}
				break;
			}
			
		default:
			{
				temp_stg = 777;
			}
	}
	
	return temp_stg;
}






















int main()
{
	vector<int> V;
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
		
	// Operation Selection
		
	system("cls");
	cout << "\n\n" << endl;
	cout << " +--------------------------------------------------+" << endl;
	cout << " |   Sum   of All Elements: \t" << calculator(V, 1) << endl;
	cout << " | Product of All Elements: \t" << calculator(V, 2) << endl;
	cout << " | Average of All Elements: \t" << calculator(V, 3) << endl;
	cout << " +--------------------------------------------------+" << endl;
	
	system("pause");
}

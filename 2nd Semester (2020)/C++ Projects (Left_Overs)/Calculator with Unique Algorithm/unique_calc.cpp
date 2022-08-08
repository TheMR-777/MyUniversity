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



void sort(vector<int> &V, bool op)
{
	int temp;
	for (int i=0 ; i < (V.size()-1) ; i++)
	{
		for (int j=(i+1) ; j < V.size() ; j++)
		{
			if (op == 0)
			{
				if (V[j] < V[i])
				{
					temp = V[j];
					V[j] = V[i];
					V[i] = temp;
				}
			}
			else
			{
				if (V[j] > V[i])
				{
					temp = V[j];
					V[j] = V[i];
					V[i] = temp;
				}
			}
		}
	}
}





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
			cout << "- Enter Value #" << i+1 << " : ";
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
		
		// Result Generation
		
		system("cls");
		cout << "\n\n" << endl;
		cout << " +--------------------------------------------------+" << endl;
		cout << " |   Sum   of All Elements: \t" << calculator(V, 1) << endl;
		cout << " | Product of All Elements: \t" << calculator(V, 2) << endl;
		cout << " | Average of All Elements: \t" << calculator(V, 3) << endl;
		cout << " +--------------------------------------------------+" << endl;
		cout << " |" << endl;
		cout << " | Your Sequence of Entering Numbers:" << endl;
		cout << " |---------------------------------------------------" << endl;
		cout << " |  ";
		for (int i=0 ; i < V.size() ; i++)
		{
			cout << V[i];
			
			if ( i != (V.size() -1))
			{
				cout << ", ";
			}
		}
		cout << "  |" << endl;
		cout << " |---------------------------------------------------" << endl;
		
		
		cout << " |" << endl;
		cout << " | Numbers in Ascending Sequence:" << endl;
		cout << " |---------------------------------------------------" << endl;
		cout << " |  ";
		sort(V, 0);
		for (int i=0 ; i < V.size() ; i++)
		{
			cout << V[i];
			
			if ( i != (V.size() -1))
			{
				cout << ", ";
			}
		}
		cout << "  |" << endl;
		cout << " |---------------------------------------------------" << endl;
		
		
		cout << " |" << endl;
		cout << " | Numbers in Descending Sequence:" << endl;
		cout << " |---------------------------------------------------" << endl;
		cout << " |  ";
		sort(V, 1);
		for (int i=0 ; i < V.size() ; i++)
		{
			cout << V[i];
			
			if ( i != (V.size() -1))
			{
				cout << ", ";
			}
		}
		cout << "  |" << endl;
		cout << " +---------------------------------------------------" << endl;
		
		cout << "\n\n\n" << endl;
		system("pause");
	}
	while ( true );
}





















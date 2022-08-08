#include <iostream>
#include <vector>
using namespace std;


vector<int> sort(vector<int> V, bool op)
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
	
	return V;
}




int main()
{
	// For Neat Environment

		system("cls");
	

	// Initialization
	
		vector<int> V;
		int temp=1;

	
	// Taking Input
	
		cout << "\n- Enter your Values 1-by-1 (Enter 0 when finished entering Values)" << endl << endl;
			
			
			// Taking Input while your Input != 0
			
			for ( int i = 0 ; temp!=0 ; i++)
			{
				temp=0;
				cout << "Enter Value #" << i+1 << " : ";
				cin >> temp;
				
				if (temp != 0)
				{
					V.push_back(temp);
				}
			}


	// Results Generation
		
		
		system("cls");
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

		V=sort(V, 0);

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

		V=sort(V, 1);

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
		
	// Finalizing

		cout << "\n\n\n" << endl;
		system("pause");
		main();
}

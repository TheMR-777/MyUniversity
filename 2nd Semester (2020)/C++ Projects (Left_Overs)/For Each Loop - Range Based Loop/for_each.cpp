#include <iostream>
#include <vector>
using namespace std;

// Use in Compiler Path : -std=c++11 , if u r having issues in compilation, specially in Dev-C++ or C-Free

int main()
{
	// Initialization

		int n=1;
		vector<int> V;


	// Introduction
		
		cout << "\n" << endl;
		cout << "Enter Numbers 1-by-1 below ..." << endl;
		cout << "Enter 0 when finished Entering Values" << endl;
		cout << endl;
	
	
	// Normal "For" Loop for Taking Input
	
		for(int i=0 ; n != 0 ; i++)
		{
			
			cout << "- Enter Element #" << i+1 << " : ";
			cin >> n;
			
			// Break Function
			
			if (n != 0)
			{
				V.push_back(n);
			}
		}
		cout << endl;
	
	
	// Output using "For Each" / "Range Based" Loop
	// The Colon ":" below, just Synchronizes integer "n" with vector<int> "V"
	// The "n" should have the same DATA_TYPE as of vector
	
		for (int n : V)
		{
			cout << "Output Values : " << n << endl;
		}
}

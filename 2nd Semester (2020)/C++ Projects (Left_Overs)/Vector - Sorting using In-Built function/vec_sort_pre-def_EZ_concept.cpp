#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
    // Creating a Vector of some values

	    vector<int> V = { 4,2,6,3,7,9,1,3,2,1,44,43 };

    // Using the Built-In sort Function

	    sort(V.begin(), V.end());

    // Displaying the Output

        for (decltype(V[0]) &i : V)
        {
            cout << i << endl;
        }
}
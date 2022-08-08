#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> V = {10, 20, 30};

    // V.pop_back();
    // V.push_back(40);
    V.clear();
    V.shrink_to_fit();

    for (int i=0 ; i < V.size() ; i++)
    {
        cout << V[i] << endl;
    }
}
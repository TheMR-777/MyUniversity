#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ofstream file ("new_file.txt");


    vector<string> N;
    for(int i=0 ; i>=0 ; i++)
    {
        string n;
        cout << "- Enter Name #" << i+1 << " : ";
        cin >> n;

        if (n == "0")
        {
            break;
        }
        else
        {
            N.push_back(n);
        }
    }

    for (int i = 0; i < N.size() ; i++)
    {
        file << N[i] << endl;
    }
    

}
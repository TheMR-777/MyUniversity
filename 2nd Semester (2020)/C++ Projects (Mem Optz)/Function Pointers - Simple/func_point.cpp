#include <iostream>
#include <vector>
using namespace std;

void Printer(int value)
{
    cout << "Value : " << value << endl;
}

void Reciever(vector<int> &val , void(*point_func)(int))
{
    for ( int i=0 ; i < val.size() ; i++ )
    {
        point_func(val[i]);
    }
}

int main()
{
    // Initialization

        vector<int> values = { 7 , 3 , 1 , 34 , 4 };
        Reciever(values , Printer);
}
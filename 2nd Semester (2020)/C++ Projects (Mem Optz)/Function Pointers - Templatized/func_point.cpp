#include <iostream>
#include <vector>
using namespace std;

template<typename ANY>
void Printer(ANY value)
{
    cout << "Value : " << value << endl;
}

template<typename ANY>
void Reciever(vector<ANY> &val , void(*point_func)(ANY))
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
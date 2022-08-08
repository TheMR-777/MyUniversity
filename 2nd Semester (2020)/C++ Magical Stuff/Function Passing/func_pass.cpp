#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void Printer(int data)
{
    cout << data << endl;
}

void Receiver(vector<int>& values, function<void(int)> any_func)
{
    for (int &i : values)
    {
        any_func(i);
    }
}

int main()
{
    vector<int> values = { 2,3,6,22,5,3,7,8,1 };
    Receiver(values, Printer);
}
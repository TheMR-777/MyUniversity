#include <iostream>
using namespace std;

int main(int arg_count, char** arg)
{
    int sum = 0;

    for (int i = 0; i < arg_count; ++i)
    {
        cout << *(int*)&(arg[arg_count]) << endl;
        sum += *(int*)&(arg[arg_count]);
    }

    return sum;
}
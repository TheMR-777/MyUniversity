#include <iostream> 
using namespace std;

int main()
{
    // Initialization

        const int const_var = 75;
        int *breaker;

    // Breaking the Rule

        breaker = (int*)&const_var;
        *breaker = 10;

    // Output

        cout << *breaker << endl;
        cout << const_var;
}
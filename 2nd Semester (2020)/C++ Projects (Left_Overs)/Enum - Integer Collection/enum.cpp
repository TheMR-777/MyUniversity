#include <iostream> 
using namespace std;

int main()
{
    enum Level
    {
        A = 5 , B , C
    };

    cout << "Level A - " << A << endl;
    cout << "Level B - " << B << endl;
    cout << "Level C - " << C << endl;
}
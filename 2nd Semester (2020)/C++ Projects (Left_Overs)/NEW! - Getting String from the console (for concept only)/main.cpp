#include <iostream>
using namespace std;

int main(int a_size , char ** a_input)
{
    system("cls");
    cout << "You entered : " << a_size << " elements, details below :" << endl;

    for ( int i=0 ; i < sizeof(a_input) ; i++ )
    {
        cout << a_input[i] << " ";
    }

    cin.get();
}
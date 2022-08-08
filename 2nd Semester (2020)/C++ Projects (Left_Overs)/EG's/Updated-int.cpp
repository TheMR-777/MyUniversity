#include<iostream>
using namespace std;

void life(int &S)
{
    if ( S == 0 )
    {
        cout << "You died.Remain in peace in the afterworld. Goodbye" << endl;
    }
    else if ( S == 1 )
    {
        cout << "Luckyl you are alive. Congratulations" << endl;
    }
    else
    {
        cout << "Invalid Input" << endl;
    }
}


int main()
{
	int status;
    cout << "Heared that you had an accident recently. ALAS! Now, Tell me if ou are alive or not" << endl;
    cout << "Enter 1 if u r alive" << endl;
    cout << "Enter 0 if u r dead" << endl;
    cout << " > ";
    cin >> status;
    

	life(status);
	return 0;
}

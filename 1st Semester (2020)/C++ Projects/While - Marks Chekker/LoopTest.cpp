#include <iostream>
using namespace std;


int main(int argc, char** argv) 
{
	system("color B");
	int a;
	x:
	cout << "\n- Enter Your Marks: ";
	cin >> a;
	while (a<18)
	{
		cout << "\n- You are Failed! \n\n- Enter Next Marks: ";
		cin >> a;
		cout << endl;
	}
	cout << "\n- You are pass!\n";
	goto x;
	return 777;
}

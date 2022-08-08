#include<iostream>
using namespace std;


class Array
{
	int Ar[3];

public:

	Array()
	{
		Ar[0] = 00;
		Ar[1] = 10;
		Ar[2] = 20;
	}



	int Get(int& i) const
	{
		return Ar[i];
	}

	int Get(int&& i) const
	{
		return Ar[i];
	}



	void PrintAll()
	{
		for (int i = 0; i < (sizeof(Ar) / sizeof(int)); i++)
		{
			cout << "Element #" << i << " is : " << Ar[i] << endl;
		}
	}

	int size()
	{
		return 3;
	}
};


int main()
{
	// Initialization

		Array A;


	// Function Tests

		A.PrintAll();
}
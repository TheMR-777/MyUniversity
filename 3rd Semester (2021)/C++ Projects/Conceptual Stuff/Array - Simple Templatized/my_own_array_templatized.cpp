#include<iostream>
using namespace std;


template<typename T, int N>
class Array
{
	T Ar[N];

public:

	Array()
	{
		for (int i = 0; i < N; i++)
		{
			Ar[i] = i * 100;
		}
	}



	int Get(int& i) const
	{
		return Ar[i];
	}

	int Get(int&& i) const
	{
		return Ar[i];
	}



	void PrintAll() const
	{
		for (int i = 0; i < N; i++)
		{
			cout << "Element #" << i << " is : " << Ar[i] << endl;
		}
	}

	int size()
	{
		return N;
	}
};


int main()
{
	// Initialization

		Array<int, 5> A;


	// Function Tests

		A.PrintAll();
}
#include <iostream> 
#include <chrono>
#include <vector>
#include <array>
using namespace std;

struct Timer
{
	chrono::time_point<chrono::steady_clock> start, end;

	Timer()
	{
		start = chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = chrono::high_resolution_clock::now();
		cout << "Time taken : [ " << (end - start).count() / 1000000.0 << "ms ]" << endl;
	}
};




void H_Vector()
{
	{
		Timer Tim_Vc;
		vector<int> V;

		V.push_back(4);
		V.push_back(3);
		V.push_back(7);
		V.push_back(6);
		V.push_back(5);
		V.push_back(1);
		V.push_back(3);
		V.push_back(2);
		V.push_back(10);
		V.push_back(9);

		for (int &val : V)
		{
			cout << "Values : " << val << endl;
		}
	}
	cout << endl;
}

void S_Vector()
{
	{
		Timer Tim_Vc;
		vector<int> V = { 4,3,7,6,5,1,3,2,10,9 };

		for (int &val : V)
		{
			cout << "Values : " << val << endl;
		}
	}
	cout << endl;
}

void STL_Array()
{
	{
		Timer Tim_Vc;
		array<int, 10> A = { 4,3,7,6,5,1,3,2,10,9 };

		for (int &val : A)
		{
			cout << "Values : " << val << endl;
		}
	}
	cout << endl;
}

void Array()
{
	{
		Timer Tim_Vc;
		int A[10] = { 4,3,7,6,5,1,3,2,10,9 };

		for (int &val : A)
		{
			cout << "Values : " << val << endl;
		}
	}
	cout << endl;
}

int main()
{
	X:
	cin.get();
	cout << " - STL_Arrays" << endl;
	cout << "---------------" << endl;
	STL_Array();

	cin.get();
	cout << " - Arrays" << endl;
	cout << "-----------" << endl;
	Array();

	cin.get();
	cout << " - Vectors (Stack)" << endl;
	cout << "--------------------" << endl;
	S_Vector();

	cin.get();
	cout << " - Vectors (HEAP)" << endl;
	cout << "--------------------" << endl;
	H_Vector();
	goto X;
}
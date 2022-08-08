#include<iostream>
#define Log(x) cout << x << endl
using namespace std;


template<typename T>
void Print(T val)
{
	Log(val);
}



int main()
{
	// Template Calling in Regular way
	// --------------------------------

		Print(5);
		Print("when added with 10.78, gives");
		Print(15.78f);


	// Template Calling in Specific way
	// --------------------------------

		Print<int>(5);
		Print<string>("when added with 10.78, gives");
		Print<float>(15.78f);
}
#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


class Car
{
	string name;
	string model;

	public:

		Car(string n, string m)
			: name(n), model(m) {}

		void Print()
		{
			Log("Name of the Car  : " << name);
			Log("Model of the Car : " << model);
		}
};


int main()
{
	// 1. Initialization on Stack
	// (Regular Object)
	// ==----------------------==

		Log("");
		Car C1("BMW", "2021 - Stack Performance");
		C1.Print();


	// 2. Initialization on Stack
	// (Pointer of Object)
	// ==----------------------==

		Log("");
		Car* C2 = &C1;
		C2->Print();


	// 3. Initialization on Heap
	// ==----------------------==

		Log("");
		Car* C3 = new Car("BMW", "2021 - Heap Performance");
		C3->Print();
		delete C3;
}
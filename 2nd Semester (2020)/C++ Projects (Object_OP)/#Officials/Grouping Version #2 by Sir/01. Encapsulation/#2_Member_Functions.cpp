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

		void PrintAll()
		{
			Log("PrintAll() called!");
			Log("Name of the Car  : " << name);
			Log("Model of the Car : " << model);
		}

		void PrintName()
		{
			Log("PrintName() called!");
			Log("Name of the Car  : " << name);
		}

		void PrintModel()
		{
			Log("PrintModel() called!");
			Log("Model of the Car : " << model);
		}
};


int main()
{
	// Initialization on Stack
	// ==-------------------==

		Log("");
		Car C1("BMW", "2021 - High Performance");
		C1.PrintAll();

		Log("");
		C1.PrintName();

		Log("");
		C1.PrintModel();
}
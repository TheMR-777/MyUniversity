#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


class Base
{

	public:

		void Get_Base()
		{
			Log("Function from Base Class being called");
		}
};

class Derived : public Base
{

	public:

		void Get_Der()
		{
			Log("Function from Derived Class being called");
		}
};


int main()
{
	// 01. Dealing with Base Class
	// ===---------------------===

		Log("");
		Base B1;
		B1.Get_Base();


	// 02. Dealing with Derived Class
	// ===------------------------===

		Log("");
		Derived D1;
		D1.Get_Der();
		D1.Get_Base();
}
#include <iostream>
using namespace std;

class Singleton
{
	Singleton() {}
	Singleton(const Singleton& sgtn) = delete;

	void Internal_Test()
	{
		cout << "YES! The Singleton is working fine!" << endl;
	}

	public:

		static Singleton& Get()
		{
			static Singleton s_Instance;
			cout << "\"Get\" called Successfully" << endl;
			return s_Instance;
		}

		static void Test()
		{
			Get().Internal_Test();
		}

};



int main()
{
	system("cls");

    // Singleton Example
    
		Singleton::Test();


    // Flaws Below :

        // Not a Single Flaw :)
}
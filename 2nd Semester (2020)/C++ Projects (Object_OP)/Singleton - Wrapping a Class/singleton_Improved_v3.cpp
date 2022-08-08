#include <iostream>
using namespace std;

class Singleton
{
	Singleton() {}
	Singleton(const Singleton& sgtn) = delete;
	static Singleton s_Instance;

	void Internal_Test()
	{
		cout << "YES! The Singleton is working fine!" << endl;
	}

	public:

		static Singleton& Get()
		{
			cout << "\"Get\" called Successfully" << endl;
			return s_Instance;
		}

		static void Test()
		{
			Get().Internal_Test();
		}

};
Singleton Singleton::s_Instance;



int main()
{
	system("cls");

    // Singleton Example
    
		Singleton::Test();


    // Flaws Below :

        // s_Instance should be Instantiated in every Translated Unit
}
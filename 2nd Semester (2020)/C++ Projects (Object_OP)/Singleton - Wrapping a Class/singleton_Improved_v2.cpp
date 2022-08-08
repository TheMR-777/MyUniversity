#include <iostream>
using namespace std;

class Singleton
{
	Singleton() {}
	Singleton(const Singleton& sgtn) = delete;
	static Singleton s_Instance;

	public:

		static Singleton& Get()
		{
			cout << "\"Get\" called Successfully" << endl;
			return s_Instance;
		}

		void Test()
		{
			cout << "YES! The Singleton is working fine!" << endl;
		}
};
Singleton Singleton::s_Instance;



int main()
{
	system("cls");

    // Singleton Example
    
        Singleton::Get().Test();


    // Flaws Below :

		// We have to use .Get() everytime
        // s_Instance should be Instantiated in every Translated Unit
}
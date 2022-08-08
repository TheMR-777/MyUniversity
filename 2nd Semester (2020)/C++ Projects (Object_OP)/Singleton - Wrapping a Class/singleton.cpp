#include <iostream>
using namespace std;

class Singleton
{
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

        // Class can be Instantiated more than one times

            Singleton ST;
            ST.Test();

        // Instance can be copied

            Singleton s = Singleton::Get();

		// We've to use .Get() everytime
        // s_Instance should be Instantiated in every Translated Unit
}
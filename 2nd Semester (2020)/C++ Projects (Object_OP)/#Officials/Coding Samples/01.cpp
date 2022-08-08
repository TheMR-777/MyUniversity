#include <iostream>
#include <string>
using namespace std;


class BaseClass
{

  protected:

	  string name;

  public:

    BaseClass(string iname)
    {
      cout << "Base constructor is called" << endl;
      name = iname;
    }
};

class DerivedClass :public BaseClass
{
  public:

    DerivedClass(string a) :BaseClass(a)
    {
      cout << "Derive constructor is called" << endl;
    }
    void show()
    {
      cout << name << endl;
    }
};


int main()
{
	DerivedClass obj("John");
	obj.show();
	return 0;
}

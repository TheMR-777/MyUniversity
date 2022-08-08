#include <iostream> 
#include <memory>
using namespace std;

int main()
{
	shared_ptr<int> t0 = make_shared<int>(10);
	{
		// Scoped Work

		shared_ptr<int> t1 = t0;
		shared_ptr<int> t2 = t1;

		cout << "Pointers : " << t0.use_count() << endl;
	}

	cout << "Pointers : " << t0.use_count() << endl;
}
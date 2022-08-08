#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> values = { 3,1,4,5,2,8,7,5,6,10,9 };

	sort(values.begin(), values.end(), [](int a, int b)
	{
		if (a == 7) return false;
		if (b == 7) return true;

		return a < b;
	});

	for (int &itr : values)
	{
		cout << itr << endl;
	}
}
#include <iostream>
using namespace std;


namespace Tree25
{
	void space(const int& Required, const int& Range)
	{
		for (int i = Range - Required; i > 0; --i)
		{
			cout << " ";
		}
	}

	void Generate(const int& i, const int& Range)
	{
		// Spacing

		space(i, Range);

		// Phase #1

		for (int x = 0; x < i; ++x)
		{
			cout << "*";
		}

		// Middle Star

		cout << "*";

		// Phase #2

		for (int x = 0; x < i; ++x)
		{
			cout << "*";
		}

		// End

		cout << endl;
	}

	void Get_Tree(const int& input)
	{
		for (int i = 0; i < input; ++i)
		{
			Generate(i, input);
		}

		space(0, input); cout << "*" << endl;
	}
}

int main()
{
	// Input

	int N;
	cout << "Enter Height of the Tree: "; cin >> N;

	Tree25::Get_Tree(N);
}
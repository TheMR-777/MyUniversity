#include <iostream>
using namespace std;


class Tree25
{
	int RANGE;
	bool Button, Mid;

	void Toggle(bool& Switch)
	{
		Switch = !Switch;
	}

	void Single_Line(const int& current_range, bool Mid_Rev = 1)
	{
		for (int x = RANGE - current_range; x > 0; --x) cout << " ";
		for (int x = current_range; x > 0; --x) cout << (Button ? "*" : (x % 2 ? "*" : " "));
		cout << " " << ((Mid_Rev ? Button : !Button) ? "   " : (Mid ? " * " : "***")) << " ";
		if ((Mid_Rev && !Button) || (!Mid_Rev && Button)) Toggle(Mid);
		for (int x = current_range; x > 0; --x) cout << (!Button ? "*" : (x % 2 == 0 ? " " : "*"));
		cout << endl;
		Toggle(Button);
	}

public:

	Tree25(const int& R) : RANGE(R), Button(true), Mid(true) {}

	void Generate()
	{
		for (int x = RANGE; x > 0; x = x - 2) Single_Line(x);
		Toggle(Button);
		for (int x = 3; x <= RANGE; x = x + 2) Single_Line(x, 0);
	}
};


int main()
{
	int RANGE;
	cout << "Enter Range: "; cin >> RANGE;

	cout << endl;
	Tree25(RANGE).Generate();

	cout << endl;
	system("pause");
}
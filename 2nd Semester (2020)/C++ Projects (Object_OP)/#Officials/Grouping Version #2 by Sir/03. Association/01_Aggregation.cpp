#include<iostream>
using namespace std;
#define Work(c) cout << c << endl

// Aggregation (making pointer of object of one class in another class) concept
// Command to run this :
// clear && g++ 'Concepts/2.5.cpp' && ./a.out && rm a.out


class Chair
{

public:

	int chairNo;
	void FoldChair(bool& fold, int x)
	{

		if (fold == 1)
		{
			Work("chair folded: " << x);
		}
		else
		{
			Work("Chair folding failed:(");
		}
	}

	void UnFoldChair(bool& unfold, int y)
	{
		if (unfold == 1)
		{
			Work("chairs unfolded successfully: " << y);
		}


		else
		{
			Work("Chair unfolding failed:(" << 0);
		}
	}
};


class Room
{
	Chair* ch[5]; // creating a pointer of class chair
	float area;

public:

	void AddChair(Chair* chair1, int chairNo)

	{
		for (int i = 1; i <= chairNo; i++)
		{
			if (chairNo >= 0 && chairNo < 5)
				ch[chairNo] = chair1;   // use of chair class pointer type obj
			Work("chairs added successfully: " << i);
		}
	}

	Chair* GetChair(int chairNo)
	{
		for (int i = 1; i <= chairNo; i++)
		{

			if (chairNo >= 0 && chairNo < 5)
			{
				Work("chairs recieved successfully: " << i);
			}


		}
		return ch[chairNo];
	}
};



int main()
{
	bool fold = true, unfold = true;

	Chair ch1;
	Room r1;
	r1.AddChair(&ch1, 3);
	r1.GetChair(3);
	ch1.FoldChair(fold, 0);
	ch1.UnFoldChair(unfold, 3);
}

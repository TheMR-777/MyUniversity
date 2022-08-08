#include<iostream>
#include<chrono>
using namespace std;

class Timer
{
	chrono::time_point<chrono::high_resolution_clock> m_Start, m_End;
	long long m_Start_us, m_End_us, m_duration_us;

public:

	Timer()
	{
		m_Start = chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		m_End = chrono::high_resolution_clock::now();

		m_Start_us = chrono::time_point_cast<chrono::microseconds>(m_Start).time_since_epoch().count();
		m_End_us = chrono::time_point_cast<chrono::microseconds>(m_End).time_since_epoch().count();

		m_duration_us = m_End_us - m_Start_us;

		cout << "\nTime : [ " << m_duration_us << "us ] / [ " << m_duration_us * 0.001 << "ms ]\n" << endl;
	}
};


int Smaller_Ord(const int& a, const int& b)
{
    Timer T;
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int Smaller_Brn(const int& a, const int& b)
{
    Timer T;
	return a * (a < b) + b * (b <= a);
}



int main()
{
	int a, b;
	cout << " Enter 1st Int : ";
	cin >> a;
	cout << " Enter 2nd Int : ";
	cin >> b;
	cout << endl;

	cout << "Calling Branched Conditional Statement" << endl;
	cout << "Smaller Int is : " << Smaller_Ord(a, b) << endl;
	cout << endl;

	cout << "Calling Branchless Conditional Statement" << endl;
	cout << "Smaller Int is : " << Smaller_Brn(a, b) << endl;
}
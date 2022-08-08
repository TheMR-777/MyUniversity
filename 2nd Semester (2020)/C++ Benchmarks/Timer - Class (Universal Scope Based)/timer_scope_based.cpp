#include <iostream>
#include <chrono>
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



int main()
{
	int val=0;

	{
		Timer T;

		for (unsigned long i = 0; i < 10000000; i++)
		{
			val += 1;
		}
	}

	cout << val;
}
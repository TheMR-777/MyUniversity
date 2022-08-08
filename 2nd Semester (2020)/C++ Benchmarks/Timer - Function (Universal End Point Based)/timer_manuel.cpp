#include <iostream>
#include <chrono>
using namespace std;


namespace Timer
{
	static chrono::time_point<chrono::high_resolution_clock> m_Start, m_End;
	static long long m_Start_us, m_End_us, m_duration_us;

	void start()
	{
		m_Start = chrono::high_resolution_clock::now();
	}

	void stop()
	{
		m_End = chrono::high_resolution_clock::now();

		m_Start_us = chrono::time_point_cast<chrono::microseconds>(m_Start).time_since_epoch().count();
		m_End_us = chrono::time_point_cast<chrono::microseconds>(m_End).time_since_epoch().count();

		m_duration_us = m_End_us - m_Start_us;

		cout << "\nTime : [ " << m_duration_us << "us ] / [ " << m_duration_us * 0.001 << "ms ]\n\n";
	}
}



int main()
{
	Timer::start();

	int val=0;

	for (unsigned long i = 0; i < 10000000; i++)
	{
		val += 2;
		val -= 1;
	}
	Timer::stop();

	cout << val << '\n';

	Timer::stop();
}
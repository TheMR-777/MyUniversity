#include<iostream>
using namespace std;

template<typename T, size_t size>
class Array
{
	T m_Data[size];

public:

	// Operator Overloading

		T& operator[] (int&& index)
		{
			return m_Data[index];
		}

		T& operator[] (int& index)
		{
			return m_Data[index];
		}

		const T& operator[] (int&& index) const
		{
			return m_Data[index];
		}

		const T& operator[] (int& index) const
		{
			return m_Data[index];
		}

	// Methods

		constexpr size_t Size() const
		{
			return size;
		}
};


int main()
{
	// Initialization

		Array<int, 5> A;
		cout << A.Size();
}
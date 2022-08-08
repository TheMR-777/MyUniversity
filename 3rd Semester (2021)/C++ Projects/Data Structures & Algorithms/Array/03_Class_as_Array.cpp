#include<iostream>
using namespace std;


template<typename T>
struct Vector
{
	T m_X, m_Y, m_Z;

	Vector(T&& x, T&& y, T&& z)
		: m_X(x), m_Y(y), m_Z(z) {}
};



int main()
{
	// Initialization
	// --------------

		Vector<float> A(2.5, 4.1, 7.5);


	// Using like a Class
	// ------------------

		cout << "x-coordinate of A : [ " << A.m_X << " ]" << endl;
		cout << "y-coordinate of A : [ " << A.m_Y << " ]" << endl;
		cout << "z-coordinate of A : [ " << A.m_Z << " ]" << endl;
		cout << endl;



	// Casting A into Array
	// --------------------

		float* ptr_A = (float*)(&A);


	// Using like an Array
	// -------------------

		for (int i = 0; i < 3; i++)
		{
			cout << "Element #" << i + 1 << " of A is : [ " << ptr_A[i] << " ]" << endl;
		}
		cout << endl;



	// Using A like RAW DATA

		for (int i = 0; i < 3; i++)
		{
			cout << "Element located at Position #" << i << " of A is : [ " << *(float*)((char*)(&A) + (i) * (sizeof(float))) << " ]" << endl;
		}
}
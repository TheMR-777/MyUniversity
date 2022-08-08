#include <iostream>
#define Log(x) cout << x << endl
using namespace std;

class Complex
{
	double real, img;

public:

	// Constructors

		Complex()
			: real(0), img(0) {}

		Complex(const double& r, const double& i)
			: real(r), img(i) {}

		Complex(const double& r)
			: real(r), img(0) {}

	// Getters

		void Just_Print() const
		{
			cout << real << " + " << img << " i";
		}

		void Print() const
		{
			Log("The Complex number is : " << real << " + " << img << " i");
		}

		double get_Real() const
		{
			return real;
		}

		double get_Imaginary() const
		{
			return img;
		}

	// Setters

		void set(const double& r, const double& i)
		{
			real = r; img = i;
		}

		void set_real(const double& r)
		{
			real = r;
		}

		void set_img(const double& i)
		{
			img = i;
		}

		void clear()
		{
			real = 0.0; img = 0.0;
		}

		void equalize(const Complex& E)
		{
			real = real + fabs( real - E.real );
			img = img + fabs(img - E.img);
		}

	// Overloaded Operators

		Complex operator+(const Complex& C)
		{
			return Complex((this->real + C.real), (this->img + C.img));
		}

		Complex operator+(const double&& d)
		{
			return Complex((this->real + d), (this->img));
		}


		Complex operator-(const Complex& C)
		{
			return Complex((this->real - C.real), (this->img - C.img));
		}

		Complex operator-(const double&& d)
		{
			return Complex((this->real - d), (this->img));
		}


		Complex operator*(const Complex& C)
		{
			return Complex((this->real * C.real), (this->img * C.img));
		}

		Complex operator*(const double&& d)
		{
			return Complex((this->real * d), (this->img));
		}


		Complex operator/(const Complex& C)
		{
			return Complex((this->real / C.real), (this->img / C.img));
		}

		Complex operator/(const double&& d)
		{
			return Complex((this->real / d), (this->img));
		}


		Complex& operator+=(const Complex& C)
		{
			real += C.real; img += C.img;
			return *this;
		}

		Complex& operator-=(const Complex& C)
		{
			real -= C.real; img -= C.img;
			return *this;
		}

		Complex& operator*=(const Complex& C)
		{
			real *= C.real; img *= C.img;
			return *this;
		}

		Complex& operator/=(const Complex& C)
		{
			real /= C.real; img /= C.img;
			return *this;
		}


		

	// Friended Operators

		friend Complex operator+(const double& d, const Complex& C);
		friend Complex operator-(const double& d, const Complex& C);
		friend Complex operator*(const double& d, const Complex& C);
		friend Complex operator/(const double& d, const Complex& C);
		friend Complex operator+=(const double& d, const Complex& C);
		friend Complex operator-=(const double& d, const Complex& C);
		friend Complex operator*=(const double& d, const Complex& C);
		friend Complex operator/=(const double& d, const Complex& C);
};


Complex operator+(const double& d, const Complex& C)
{
	return Complex((C.real + d), C.img);
}

Complex operator-(const double& d, const Complex& C)
{
	return Complex((d - C.real), C.img);
}

Complex operator*(const double& d, const Complex& C)
{
	return Complex((C.real * d), C.img);
}

Complex operator/(const double& d, const Complex& C)
{
	return Complex((d / C.real), C.img);
}

Complex operator+=(const double& d, const Complex& C)
{
	return Complex((C.real + d), C.img);
}

Complex operator-=(const double& d, const Complex& C)
{
	return Complex((d - C.real), C.img);
}


Complex operator*=(const double& d, const Complex& C)
{
	return Complex((d * C.real), C.img);
}

Complex operator/=(const double& d, const Complex& C)
{
	return Complex((d / C.real), C.img);
}




void Print_Result(const Complex& C)
{
	Log("Result = " << C.get_Real() << " + " << C.get_Imaginary() << "i");
}


int main()
{
	// Initialization

		Complex A(4.6, 2.8);
		Complex B(7.4, 4.9);
		A = B;
		Print_Result(A);
		Print_Result(B);


	// Plus Operator

		Log("\n [ + ] \n");
		Print_Result(A + B);
		Print_Result(A + 7);
		Print_Result(7 + B);


	// Subtract Operator

		Log("\n [ - ] \n");
		Print_Result(A - B);
		Print_Result(B - A);
		Print_Result(A - 7);
		Print_Result(7 - B);


	// Multiplication Operator

		Log("\n [ * ] \n");
		Print_Result(A * B);
		Print_Result(A * 7);
		Print_Result(7 * B);


	// Division Operator

		Log("\n [ / ] \n");
		Print_Result(A / B);
		Print_Result(B / A);
		Print_Result(A / 7);
		Print_Result(7 / B);


	// += Operator

		Log("\n [ += ] \n");
		Print_Result(A += B);
		Print_Result(B += A);
		Print_Result(A += 7);
		Print_Result(7 += B);


	// -= Operator

		Log("\n [ -= ] \n");
		Print_Result(A -= B);
		Print_Result(B -= A);
		Print_Result(A -= 7);
		Print_Result(7 -= B);


	// *= Operator

		Log("\n [ *= ] \n");
		Print_Result(A *= B);
		Print_Result(B *= A);
		Print_Result(A *= 7);
		Print_Result(7 *= B);


	// /= Operator

		Log("\n [ /= ] \n");
		Print_Result(A /= B);
		Print_Result(B /= A);
		Print_Result(A /= 7);
		Print_Result(7 /= B);
}
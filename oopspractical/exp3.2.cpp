// C++ Program to Demonstrate
// Operator Overloading
#include <iostream>
using namespace std;

class Complex {
private:
	int real, imag;

public:
	Complex(int r = 0, int i = 0)
	{
		real = r;
		imag = i;
	}

	// This is automatically called when '+' is used with
	// between two Complex objects
Complex operator+(Complex &c2){
	Complex c3;
	c3.real=this->real+c2.real;
	c3.imag=this->real+c2.real;
	return c3;
}
	void print() { cout << real << " + i" << imag << '\n'; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1+(c1);
	c3.print();
}


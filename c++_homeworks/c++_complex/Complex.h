#pragma once
#include <iostream>
#include <cmath>

class ComplexNumber{
	public:
	int imaginary_part;
	int real_part;
	ComplexNumber();
	ComplexNumber(double);
	ComplexNumber(double, double);
	friend std::ostream& operator<<(std::ostream& stream, const ComplexNumber& number);
	ComplexNumber &operator+(const ComplexNumber& number);
	ComplexNumber &operator-(const ComplexNumber& number);
	ComplexNumber &operator*(const ComplexNumber& number);
	ComplexNumber &operator/(const ComplexNumber& number);
	ComplexNumber &operator+=(const ComplexNumber& number);
	ComplexNumber &operator/=(const ComplexNumber& number);
	ComplexNumber &operator*=(const ComplexNumber& number);
	ComplexNumber &operator-=(const ComplexNumber& number);
	bool operator==(const ComplexNumber& number);
	bool operator!=(const ComplexNumber& number);
	double getAmplitude();
	double getPhase();
	~ComplexNumber();
}

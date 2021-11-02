#pragma once
#include <iostream>
#include <cmath>

class ComplexNumber{
	public:
	int imaginary_part;
	int real_part;
	ComplexNumber();
	ComplexNumber(double real);
	ComplexNumber(double real, double imaginary);
	friend std::ostream& operator<<(std::ostream& stream, const ComplexNumber& number);
	friend ComplexNumber operator+(ComplexNumber first, ComplexNumber other);
	friend ComplexNumber operator-(ComplexNumber first, ComplexNumber other);
	friend ComplexNumber operator*(ComplexNumber first, ComplexNumber other);
	friend ComplexNumber operator/(ComplexNumber first, ComplexNumber other);
	ComplexNumber &operator+=(ComplexNumber other);
	ComplexNumber &operator/=(ComplexNumber other);
	ComplexNumber &operator*=(ComplexNumber other);
	ComplexNumber &operator-=(ComplexNumber other);
	friend bool operator==(ComplexNumber first, ComplexNumber other);
	friend bool operator!=(ComplexNumber first, ComplexNumber other);
	double getAmplitude();
	double getPhase();
};

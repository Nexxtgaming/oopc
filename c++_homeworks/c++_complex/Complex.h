#pragma once
#include <cmath>
#include <iostream>

class ComplexNumber {
  public:
	double imaginary_part;
	double real_part;
	ComplexNumber(double real = 0, double imaginary = 0);
	ComplexNumber& operator+=(ComplexNumber other);
	ComplexNumber& operator/=(ComplexNumber other);
	ComplexNumber& operator*=(ComplexNumber other);
	ComplexNumber& operator-=(ComplexNumber other);
	double getAmplitude();
	double getPhase();
};
ComplexNumber operator+(ComplexNumber first, ComplexNumber other);
ComplexNumber operator-(ComplexNumber first, ComplexNumber other);
ComplexNumber operator*(ComplexNumber first, ComplexNumber other);
ComplexNumber operator/(ComplexNumber first, ComplexNumber other);
std::ostream& operator<<(std::ostream& stream, ComplexNumber number);
bool operator==(ComplexNumber other);
bool operator!=(ComplexNumber other);

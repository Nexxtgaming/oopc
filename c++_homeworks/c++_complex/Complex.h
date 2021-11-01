#pragma once

class ComplexNumber{
	public:
	int imaginary_part;
	int real_part;
	ComplexNumber();
	ComplexNumber(double);
	ComplexNumber(double, double);
	const ComplexNumber &operator<<(ostream& stream, const ComplexNumber& number);
	const ComplexNumber &operator+(const ComplexNumber& number);
	const ComplexNumber &operator-(const ComplexNumber& number);
	const ComplexNumber &operator*(const ComplexNumber& number);
	const ComplexNumber &operator/(const ComplexNumber& number);
	double getAmplitude();
	double getPhase();
	~ComplexNumber();
}

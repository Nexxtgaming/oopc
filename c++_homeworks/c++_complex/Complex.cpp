#include "Complex.h"

using namespace std;

ComplexNumber::ComplexNumber(double real, double imaginary) {
	this->real_part = real;
	this->imaginary_part = imaginary;
}
std::ostream& operator<<(std::ostream& stream, ComplexNumber number) {
	stream << number.real_part << " " << number.imaginary_part << "i ";
	return stream;
}
ComplexNumber operator+(ComplexNumber first, ComplexNumber other) {
	ComplexNumber newComplexNumber = first;
	newComplexNumber += other;
	return newComplexNumber;
}
ComplexNumber operator-(ComplexNumber first, ComplexNumber other) {
	ComplexNumber newComplexNumber = first;
	newComplexNumber -= other;
	return newComplexNumber;
}
ComplexNumber operator*(ComplexNumber first, ComplexNumber other) {
	ComplexNumber newComplexNumber = first;
	newComplexNumber *= other;
	return newComplexNumber;
}
ComplexNumber operator/(ComplexNumber first, ComplexNumber other) {
	ComplexNumber newComplexNumber = first;
	newComplexNumber /= other;
	return newComplexNumber;
}
ComplexNumber& ComplexNumber::operator+=(ComplexNumber other) {
	this->real_part += other.real_part;
	this->imaginary_part += other.imaginary_part;
	return *this;
}
ComplexNumber& ComplexNumber::operator-=(ComplexNumber other) {
	this->real_part -= other.real_part;
	this->imaginary_part -= other.imaginary_part;
	return *this;
}
ComplexNumber& ComplexNumber::operator*=(ComplexNumber other) {
	this->real_part = this->real_part * other.real_part -
					  this->imaginary_part * other.imaginary_part;
	this->imaginary_part = this->real_part * other.imaginary_part +
						   this->imaginary_part * other.real_part;
	return *this;
}
ComplexNumber& ComplexNumber::operator/=(ComplexNumber other) {
	double new_real_part = (this->real_part * other.real_part +
					   this->imaginary_part * other.imaginary_part) /
					  (pow(other.real_part, 2) + pow(other.imaginary_part, 2));
	this->imaginary_part = (this->imaginary_part * other.real_part -
							this->real_part * other.imaginary_part) /
						   (pow(other.real_part, 2) + pow(other.imaginary_part, 2));
	this->real_part = new_real_part;
	return *this;
}
bool operator==(ComplexNumber other, ComplexNumber first) {
	if (first.real_part == other.real_part &&
		first.imaginary_part == other.imaginary_part)
		return true;
	return false;
}
bool operator!=(ComplexNumber other, ComplexNumber first) {
	if (first.real_part != other.real_part ||
		first.imaginary_part != other.imaginary_part)
		return true;
	return false;
}

double ComplexNumber::getPhase() const{
	double phase = atan2(this->imaginary_part, this->real_part);
	return phase;
}
double ComplexNumber::getAmplitude() const{
	double amplitude =
		sqrt(pow(this->imaginary_part, 2) + pow(this->real_part, 2));
	return amplitude;
}

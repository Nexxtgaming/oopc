#include "Complex.h"

using namespace std;

ComplexNumber::ComplexNumber() {
	this->real_part = 0;
	this->imaginary_part = 0;
}
ComplexNumber::ComplexNumber(double real) {
	this->real_part = real;
	this->imaginary_part = 0;
}
ComplexNumber::ComplexNumber(double real, double imaginary) {
	this->real_part = real;
	this->imaginary_part = imaginary;
}
std::ostream& operator<<(std::ostream& stream, const ComplexNumber& number){
	stream<<number.real_part<<" "<<number.imaginary_part<<"i ";
	return stream;
}
ComplexNumber operator+(ComplexNumber first, ComplexNumber other) {
	ComplexNumber newComplexNumber = first;
	newComplexNumber += other;
	return newComplexNumber;
}
ComplexNumber operator-(ComplexNumber& first, ComplexNumber& other) {
	ComplexNumber& newComplexNumber = first;
	newComplexNumber -= other;
	return newComplexNumber;
}
ComplexNumber operator*(ComplexNumber first, ComplexNumber other) {
	ComplexNumber& newComplexNumber = first;
	newComplexNumber *= other;
	return newComplexNumber;
}
ComplexNumber operator/(ComplexNumber first, ComplexNumber other) {
	ComplexNumber& newComplexNumber = first;
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
	this->real_part = (this->real_part * other.real_part +
					   this->imaginary_part * other.imaginary_part) /
					  (pow(this->real_part, 2) + pow(other.real_part, 2));
	this->imaginary_part = (this->real_part * other.imaginary_part -
							this->imaginary_part * other.real_part) /
						   (pow(this->real_part, 2) + pow(other.real_part, 2));
	return *this;
}
bool operator==(ComplexNumber first, ComplexNumber other){
	if (first.real_part == other.real_part &&
		first.imaginary_part == other.imaginary_part)
		return true;
	return false;
}
bool operator!=(ComplexNumber first, ComplexNumber other){
	if (first.real_part != other.real_part ||
		first.imaginary_part != other.imaginary_part)
		return true;
	return false;
}

double ComplexNumber::getPhase() {
	double phase = atan2(this->imaginary_part, this->real_part);
	return phase;
}
double ComplexNumber::getAmplitude() {
	double amplitude = sqrt(pow(this->imaginary_part, 2) + pow(this->real_part, 2));
	return amplitude;
}


#include "Complex.h"

using namespace std;

ComplexNumber::ComplexNumber(){
    this->real_part = 0;
    this->imaginary_part = 0;
}
ComplexNumber::ComplexNumber(double real){
    this->real_part = real;
    this->imaginary_part = 0;
}
ComplexNumber::ComplexNumber(double real, double imaginary){
    this->real_part = real;
    this->imaginary_part = imaginary;
}
ComplexNumber& ComplexNumber::operator+(const ComplexNumber& other){
    double real = this->real_part + other.real_part;
    double imaginary = this->imaginary_part + other.imaginary_part;
    ComplexNumber newComplexNumber = ComplexNumber(real, imaginary);
    return newComplexNumber;
}
ComplexNumber& ComplexNumber::operator-(const ComplexNumber& other){
    double real = this->real_part - other.real_part;
    double imaginary = this->imaginary_part - other.imaginary_part;
    ComplexNumber newComplexNumber = ComplexNumber(real, imaginary);
    return newComplexNumber;

}
ComplexNumber& ComplexNumber::operator*(const ComplexNumber& other){
    double real = this->real_part*other.real_part - this->imaginary_part*other.imaginary_part;
    double imaginary = this->real_part*other.imaginary_part + this->imaginary_part*other.real_part;
    ComplexNumber newComplexNumber = ComplexNumber(real, imaginary);
    return newComplexNumber;
}
ComplexNumber& ComplexNumber::operator/(const ComplexNumber& other){
    double real = (this->real_part*other.real_part + this->imaginary_part*other.imaginary_part) / (pow(this->real_part,2)+pow(other.real_part, 2));
    double imaginary = (this->real_part*other.imaginary_part - this->imaginary_part*other.real_part) / (pow(this->real_part,2)+pow(other.real_part, 2));
    ComplexNumber newComplexNumber = ComplexNumber(real, imaginary);
    return newComplexNumber;
}
ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other){
    this->real_part += other.real_part;
    this->imaginary_part +=other.imaginary_part;
    return *this;
}
ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other){
    this->real_part -= other.real_part;
    this->imaginary_part -=other.imaginary_part;
    return *this;
}
ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other){
    this->real_part = this->real_part*other.real_part - this->imaginary_part*other.imaginary_part;
    this->imaginary_part = this->real_part*other.imaginary_part + this->imaginary_part*other.real_part;
    return *this;
}
ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other){
    this->real_part = (this->real_part*other.real_part + this->imaginary_part*other.imaginary_part) / (pow(this->real_part,2)+pow(other.real_part, 2));
    this->imaginary_part = (this->real_part*other.imaginary_part - this->imaginary_part*other.real_part) / (pow(this->real_part,2)+pow(other.real_part, 2));
    return *this;
}
bool ComplexNumber::operator==(const ComplexNumber& other){
    if(this->real_part == other.real_part && this->imaginary_part == other.imaginary_part)return true;
    return false;
}
bool ComplexNumber::operator!=(const ComplexNumber& other){
    if(this->real_part != other.real_part || this->imaginary_part != other.imaginary_part)return true;
    return false;
}
double ComplexNumber::getPhase(){
    double phase = atan2(this->imaginary_part, this->real_part);
    return phase;
}
double ComplexNumber::getAmplitude(){
    double phase = sqrt(pow(this->imaginary_part,2)+pow(this->real_part, 2));
    return phase;
}
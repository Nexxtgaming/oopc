#include "Complex.h"
#include <complex>
#include <iostream>

using namespace std;

void test_phase_amp() {
	double real = 4.5;
	double imaginary = 9;
	complex<double> expectedComplex(real, imaginary);
	double expectedAmplitude = abs(expectedComplex);
	double expectedPhase = arg(expectedComplex);

	const ComplexNumber mycomplex(real, imaginary);
	double myPhase = mycomplex.getPhase();
	double myAmplitude = mycomplex.getAmplitude();
	cout << "expected amplitude " << expectedAmplitude << endl;
	cout << "my amplitude " << myAmplitude << endl;
	cout << "expected phase" << expectedPhase << endl;
	cout << "my phase" << myPhase << endl;
}

void test_operators() {
	ComplexNumber a = ComplexNumber();
	ComplexNumber b = ComplexNumber(10);
	ComplexNumber c = ComplexNumber(12.3, 3);
	ComplexNumber eq1 = a - 7;
	ComplexNumber eq3 = b / 5;
	
	ComplexNumber first = ComplexNumber(2, 3);
	ComplexNumber second = ComplexNumber(5, -2);
	ComplexNumber result = first / second;
	cout<<result<<endl;
	a += b += c;
	(a += b) += c;
	a *= b *= c;
	(a *= b) *= c;
	cout<<eq1<<endl;
	ComplexNumber eq2 = 7 + a;
	cout<<eq3<<endl;
	ComplexNumber eq4 = 5 * b;

	if (c == 3.5) {
		cout << c << "equals" << 3.5 << endl;
	} else {
		cout << c << "not equals" << 3.5 << endl;
	}
	if (3.5 != c) {
		cout << 3.5 << "equals" << c << endl;
	} else {
		cout << 3.5 << "not equals" << c << endl;
	}
}

int main() {
	test_operators();
	test_phase_amp();
}

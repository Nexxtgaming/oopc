#include "Poly.h"

using namespace std;

void display(const Poly& p1, const Poly& p2) {
	cout << "Polynomial p1: " << p1 << endl;
	cout << "Polynomial p2: " << p2 << endl;	
}

int main() {
	Poly p1;															// Declare object representing polynomial p1	
	p1[3] = 2;															// Specify coefficients of p1 = 2x^3 + 3.6x + 7
	p1[1] = 3.6;
	p1[0] = 7;

	Poly p2 = 5;														// Declare object representing polynomial p2 = 5
	p2[4] = 1;															// Specify additional coefficients of p2 = x^4 - 6x^2 + 3x + 5
	p2[2] = -6;
	p2[1] = 3;
	
	display(p1, p2);
	//test(p1, p2);
}
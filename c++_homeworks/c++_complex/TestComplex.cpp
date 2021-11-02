#include <iostream>
#include "Complex.h"

using namespace std;

void test_operators(){
    ComplexNumber a = ComplexNumber();
    ComplexNumber b = ComplexNumber(10);
    ComplexNumber c = ComplexNumber(12.3, 3);
    a += b += c;
    (a += b) += c;
    a *= b *= c;
    (a *= b) *= c;
    ComplexNumber eq1 = a + 7;
    ComplexNumber eq2 = 7 + a;
    ComplexNumber eq3 = b * 5;
    ComplexNumber eq4 = 5 * b;
    
    if(c==3.5){
	cout<<c<<"equals"<<3.5<<endl;
	}else{
		cout<<c<<"not equals"<<3.5<<endl;
		}
	if(3.5 == c){
		cout<<3.5<<"equals"<<c<<endl;
	}else{
		cout<<3.5<<"not equals"<<c<<endl;
	}
   // 3.5 == c;   
}

int main(){
	test_operators();
}

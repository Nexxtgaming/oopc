#include <iostream>
#include <Complex.h>

void test_operators(){
    ComplexNumber a = ComplexNumber();
    ComplexNumber b = ComplexNumber(10);
    ComplexNumber c = ComplexNumber(12.3, 3);
    a += b += c;
    (a += b) += c;
    a *= b *= c;
    (a *= b) *= c;
    a + 7;
    7 + a;
    b * 5;
    5 * b;
    c == 3.5;
    3.5 == c;   
}

int main(){

}
#pragma once
#include <iostream>
#include <map> 
#include <cmath>

class Poly{
    private:
    std::map <int, double> map;
    public:
    Poly();
    Poly(double number);
    double& operator[](int i);
	friend std::ostream& operator<<(std::ostream& stream, const Poly& poly);
	friend Poly operator+(Poly first, Poly other);
	friend Poly operator-(Poly first, Poly other);
    const Poly &operator=(const Poly &other);
    Poly operator-() const;
    friend Poly operator*(Poly first, Poly second);
    double operator()(double number)const;


};
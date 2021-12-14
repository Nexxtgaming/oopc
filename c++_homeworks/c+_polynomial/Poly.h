#pragma once
#include <cmath>
#include <iostream>
#include <map>

class Poly {
  private:
	std::map<int, double> map;

  public:
	Poly();
	Poly(double number);
	double& operator[](int i);
	friend std::ostream& operator<<(std::ostream& stream, const Poly& poly);
	friend Poly operator+(const Poly& first, const Poly& other);
	friend Poly operator-(const Poly& first, const Poly& other);
	const Poly& operator=(const Poly& other);
	Poly operator-() const;
	friend Poly operator*(const Poly& first, const Poly& second);
	double operator()(double number) const;
};

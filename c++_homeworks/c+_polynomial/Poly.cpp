#include "Poly.h"

Poly::Poly() {
	std::pair<int, double> newPair(0, 0);
	this->map.insert(newPair);
}
Poly::Poly(double number) {
	std::pair<int, double> newPair(0, number);
	this->map.insert(newPair);
}
double& Poly::operator[](int i) { return this->map[i]; }
std::ostream& operator<<(std::ostream& stream, const Poly& poly) {
	bool isNotAllZero = false;
	for (auto itr = poly.map.rbegin(); itr != poly.map.rend(); ++itr) {
		int power = itr->first;
		double coefficient = itr->second;
		std::string begin;
		if (itr == poly.map.rbegin()) {
			begin = " ";
		} else if (coefficient < 0) {
			begin = " - ";
			coefficient = -coefficient;
		} else {
			begin = " + ";
		}
		if (coefficient == 0) {
			continue;
		} else {
			isNotAllZero = true;
		}
		if (coefficient == 1) {
			stream << begin << "x^" << power;
			continue;
		}
		if (power == 0) {
			stream << begin << coefficient;
		} else if (power == 1) {
			stream << begin << coefficient << "x";
		} else {
			stream << begin << coefficient << "x^" << power;
		}
	}
	if (!isNotAllZero) {
		stream << " 0 " << std::endl;
	}

	return stream;
}
const Poly& Poly::operator=(const Poly& other) {
	if (this == &other)
		return *this;
	this->map = other.map;
	return *this;
}
Poly operator+(const Poly& first, const Poly& other) {
	Poly result = first;
	for (auto itr = other.map.rbegin(); itr != other.map.rend(); ++itr) {
		int otherPower = itr->first;
		double otherCoeff = itr->second;
		auto firstItr = first.map.find(otherPower);
		if (firstItr != first.map.end()) {
			double firstCoeff = firstItr->second;
			double newCoeff = otherCoeff + firstCoeff;
			result.map[otherPower] = newCoeff;

		} else {
			result.map.insert(std::make_pair(itr->first, itr->second));
		}
	}
	return result;
}
Poly operator-(const Poly& first, const Poly& other) {
	Poly result = first + (-other);
	return result;
}
Poly Poly::operator-() const {
	Poly result = Poly();
	for (auto itr = this->map.rbegin(); itr != this->map.rend(); ++itr) {
		int power = itr->first;
		double coeff = itr->second;
		double newCoeff = -coeff;
		if (power == 0 && coeff != 0) {
			result.map[power] = newCoeff;
		} else {
			result.map.insert(std::make_pair(power, newCoeff));
		}
	}
	return result;
}
Poly operator*(const Poly& first, const Poly& second) {
	Poly result = Poly();
	for (auto itr = first.map.rbegin(); itr != first.map.rend(); ++itr) {
		int firstPower = itr->first;
		double firstCoeff = itr->second;
		for (auto secondItr = second.map.rbegin();
			 secondItr != second.map.rend(); ++secondItr) {
			int secondPower = secondItr->first;
			double secondCoeff = secondItr->second;

			int newPower = firstPower + secondPower;
			double newCoeff = firstCoeff * secondCoeff;

			if (newPower == 0) {
				result.map[newPower] = newCoeff;
			} else {
				result.map.insert(std::make_pair(newPower, newCoeff));
			}
		}
	}
	return result;
}
double Poly::operator()(double number) const {
	double result = 0;
	for (auto itr = this->map.rbegin(); itr != this->map.rend(); ++itr) {
		int power = itr->first;
		double coeff = itr->second;
		result += pow(number, power) * coeff;
	}
	return result;
}

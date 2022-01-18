#pragma once
#include "Exceptions.h"
#include <fstream>
#include <iostream>
#include <string.h>

class Matrix;
class Data {
	int refCount;
	int** table;
	int x;
	int y;

  public:
	Data(int x = 0, int y = 0);
	Data(const Data& other);
	int getValue(int x, int y);
	~Data();
	friend class Matrix;
};

class Matrix {
	mutable Data* data;

	void deleteTable();
	void resetValue(bool isMathOperation);
	void mathOperation(const Matrix& other, char choice);
	bool isCharInLine(std::string line);
	void loadFromString(std::string matrixString, int x);
	void isOutOfBounds(int x, int y) const;

  public:
	Matrix(int x, int y);
	Matrix(const Matrix& matrix);
	Matrix(std::string filename);

	int getRefCount();
	int getX() const;
	int getY() const;

	int& operator()(int x, int y);
	int operator()(int x, int y) const;

	Matrix& operator+=(const Matrix& other);
	friend Matrix operator+(const Matrix& first, const Matrix& second);

	Matrix& operator*=(const Matrix& other);
	friend Matrix operator*(const Matrix& first, const Matrix& second);

	Matrix& operator-=(const Matrix& other);
	friend Matrix operator-(const Matrix& first, const Matrix& second);

	Matrix& operator=(const Matrix& other);

	bool operator!=(const Matrix& other) const;
	bool operator==(const Matrix& other) const;

	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
	friend class Data;

	~Matrix();
};

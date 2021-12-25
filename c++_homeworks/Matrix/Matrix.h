#pragma once
#include <iostream>
#include "Exceptions.h"
#include <fstream>
#include <string.h>

class Matrix;
class Cell{
    int value;
    void changeTable(int number);
    const Matrix* calledBy;
    public:
    Cell(int number = 0);
    void operator=(int number);
    operator int() const;
    bool operator!=(const Cell& other);
    friend std::ostream& operator<<(std::ostream& stream, const Cell& cell);
    ~Cell();
    friend class Matrix;

};

class Matrix{


    mutable int* refCount;
    mutable Cell** table;
    mutable int* x;
    mutable int* y;

    void deleteTable();
    void resetValue(bool isMathOperation);
    void newValue(int x, int y)const;
    void mathOperation(const Matrix& other, char choice);
    bool isCharInLine(std::string line);
    void loadFromString(std::string matrixString, int x);


    public:
    Matrix(int x, int y); 
    Matrix(const Matrix& matrix);
    Matrix(std::string filename);

    int getRefCount();
    int getX()const;
    int getY()const;

    Cell& operator()(int x, int y)const;

    Matrix& operator+=(const Matrix& other);
    friend Matrix operator+(const Matrix& first, const Matrix& second);

    Matrix& operator*=(const Matrix& other);
    friend Matrix operator*(const Matrix& first, const Matrix& second);
    
    Matrix& operator-=(const Matrix& other);
    friend Matrix operator-(const Matrix& first, const Matrix& second);

    Matrix& operator=(const Matrix& other);

    bool operator!=(const Matrix& other)const;
    bool operator==(const Matrix& other)const;
    
    friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
    friend class Cell;

    ~Matrix();

};

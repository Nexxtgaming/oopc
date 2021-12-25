#pragma once
#include <iostream>

class IndexOutOfBonds  {
    public:
    const char * what () const throw ();
};


class NegativeIndex  {
    public:
    const char * what () const throw ();
};


class BadMatrixDeclaration  {
    public:
    const char * what () const throw ();
};

class DifferentDimensions  {
    public:
    const char * what () const throw ();
};

class MulBadDimensions  {
    public:
    const char * what () const throw ();
};

class OpenFileError  {
    public:
    const char * what () const throw ();
};

class EmptyFile  {
    public:
    const char * what () const throw ();
};


class BadInput {
    public:
    const char * what () const throw ();
};


class InvalidIndex {
    public:
    const char * what () const throw ();
};
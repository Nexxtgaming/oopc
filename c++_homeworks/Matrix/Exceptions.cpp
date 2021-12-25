#include "Exceptions.h"

const char * IndexOutOfBonds::what() const throw(){
    return "Index of Of Bonds";
}


const char * NegativeIndex::what() const throw(){
    return "Negative Index";
}


const char * BadMatrixDeclaration::what() const throw(){
    return "Matrix size cannot be less or equal 0";
}


const char * DifferentDimensions::what() const throw(){
    return "cannot add or subtract. Two matrices have different dimensions";
}


const char * MulBadDimensions::what() const throw(){
    return "cannot multiply matrices. Two matrices have inappropriate dimensions";
}


const char * OpenFileError::what() const throw(){
    return " Cannot open the file";
}


const char * EmptyFile::what() const throw(){
    return " Empty file";
}

const char * BadInput::what() const throw(){
    return " Bad input";
}


const char * InvalidIndex::what() const throw(){
    return " Matrix with dimensions 1x1 is not a matrix. it is a scalar";
}
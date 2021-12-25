#include <stdlib.h>
#include <time.h>
#include "Matrix.h"


void fillMatrix(Matrix& matrix){
	int X = matrix.getX(); 
	int Y = matrix.getY();
	for(int x = 0; x < X; x++){
		for(int y = 0; y < Y; y++){
			int value = rand()%100;
			matrix(x, y) = value;
		}
	} 
}

void displayTest(const Matrix& matrix){
    std::cout<<matrix<<std::endl;
}

void additionTest(){
	int x = rand()%10+2;
	int y = rand()%10+2;
	Matrix first(x, y);
	Matrix second(x, y);
	fillMatrix(first);
	fillMatrix(second);
	Matrix third(first);
    Matrix result = first + second;
    second += third;
}

void subtractionTest(){
	int x = rand()%10+2;
	int y = rand()%10+2;
	Matrix first(x, y);
	Matrix second(x, y);
	fillMatrix(first);
	fillMatrix(second);
	Matrix third(first);
    Matrix result = first - second;
    second -= third;
}

void multiplicationTest(){
	int x = rand()%10+2;
	int y = rand()%10+2;
	Matrix first(x, y);
	Matrix second(y, x);
	fillMatrix(first);
	fillMatrix(second);
	displayTest(second);
	displayTest(first);
	Matrix third(first);

	Matrix result = first * second;
	displayTest(result);
	third *= second;
	displayTest(third);
}

void comparisonTest(){
	int x = rand()%10+2;
	int y = rand()%10+2;
	Matrix first(x, y);
	fillMatrix(first);
	Matrix second(first);
	Matrix third(x, y);
	fillMatrix(third);
	if(first == second){
		std::cout<<"they are equal"<<std::endl;
	}
	if(first != third){
		std::cout<<"they are not equal"<<std::endl;
	}
}

void loadMatrix(std::string filename){
	Matrix matrix(filename);
	displayTest(matrix);
	
}

void getSingleElement(){
	Matrix matrix(5, 9);
	fillMatrix(matrix);
	std::cout<<matrix(1,1)<<std::endl;
	std::cout<<matrix(1,2)<<std::endl;
}



void testReferenceCount(){
	int x = 3;
	int y = 4;
	Matrix matrix_1 = Matrix(x, y);
	fillMatrix(matrix_1);
	Matrix matrix_2 = Matrix(matrix_1);
    std::cout<<matrix_1.getRefCount()<<std::endl; // should be 2
	matrix_2(1, 1) = 9;
    std::cout<<matrix_1.getRefCount()<<std::endl; // should be 1	
	Matrix matrix_3 = matrix_1;
	matrix_2 = matrix_3;
    std::cout<<matrix_1.getRefCount()<<std::endl; // should be 3	

}


void testExceptions(){

	try{
		Matrix negativeMatrix(-1, 5);
	}catch(BadMatrixDeclaration e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Matrix matrix1x1(1,1);
	}catch(InvalidIndex e){
		std::cout<<e.what()<<std::endl;
	}

	Matrix matrix1(10, 3);
	fillMatrix(matrix1);

	try{
		int value = matrix1(11,2);
	}catch(IndexOutOfBonds e){
		std::cout<<e.what()<<std::endl;
	}

	Matrix matrix2(12, 4);
	fillMatrix(matrix2);

	try{
		Matrix result = matrix2 + matrix1;
	}catch(DifferentDimensions e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Matrix result = matrix1 * matrix2;
	}catch(MulBadDimensions e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Matrix matrix("emptyfile.txt");
	}catch(EmptyFile e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Matrix matrix("errorFile.txt");
	}catch(BadInput e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Matrix matrix("doesntexist.txt");
	}catch(OpenFileError e){
		std::cout<<e.what()<<std::endl;
	}
}


int main(){
    srand(time(NULL));
	Matrix matrix_4(3, 4);
	fillMatrix(matrix_4);
	displayTest(matrix_4);
	testReferenceCount();
	comparisonTest();
	additionTest();
	subtractionTest();
	getSingleElement();
	multiplicationTest();
	loadMatrix("matrix.txt");
	testExceptions();



    return 0;
}

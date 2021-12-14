#include <iostream>

void displayTest(const Matrix& matrix){
    std::cout<<matrix<<endl;
}

void additionTest(const Matrix& first, const Matrix& second){
    Matrix result = first + second;
    displayTest(result);
    result += second;
    displayTest(result);
}

void subtractionTest(const Matrix& first, const Matrix& second){
	Matrix result = first - second;
	displayTest(result);
	result -= second;
	displayTest(result);
}

void multiplicationTest(const Matrix& first, const Matrix& second){
	Matrix result = first * second;
	displayTest(result);
	result *= second;
	displayTest(result);
}

void comparisonTest(const Matrix& first, const Matrix& second){
	if(first == second){
		std::cout<<"they are equal"<<endl;
	}
	if(first != second){
		std::cout<<"they are not eqaul"<<endl;
	}
}

void loadMatrix(std::string filename){
	Matrix matrix;
	matrix.load(filename);
	displayTest(matrix);
	
}

void singleElementAccess(const Matrix& matrix){
	std::cout<<matrix(1,1)<<endl;
}

int main(){
	int table_1[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};
	Matrix matrix_1 = Matrix(table_1);
	Matrix matrix_2 = Matrix(matrix_1);
	
	
	

    return 0;
}

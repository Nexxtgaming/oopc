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

int main(){

    return 0;
}
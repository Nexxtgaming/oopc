#include "Matrix.h"

Data::Data(int x, int y){
    this->x = x;
    this->y = y;
    this->refCount = 1;
    this->table = new int*[x];

}

Data::Data(const Data& other){
    this->x = other.x;
    this->y = other.y;
    this->refCount = 1;
    this->table = new int*[x];
    for(int i = 0; i < x; i++){
        this->table[i] = new int[y];
        for(int j = 0; j < y; j++){
            this->table[i][j] = other.table[i][j];
        }

    }
}


int Data::getValue(int x, int y){
    return this->table[x][y];
}


Data::~Data(){
    for(int i = 0; i < x; i++){
        delete[] this->table[i];
    }
    delete[] this->table;
}


Matrix::Matrix(int x, int y){ 

    if(x <= 0 || y <= 0){
        throw BadMatrixDeclaration();
    }

    if( x == 1 && y == 1){
        throw InvalidIndex();
    }
    this->data = new Data(x,y);

    for(int i = 0; i < x; i++){
        this->data->table[i] = new int[y];
        for(int j = 0; j < y; j++){
            this->data->table[i][j] = 0;
        }
    }

}


Matrix::Matrix(const Matrix& matrix){
    this->data = matrix.data;
    this->data->refCount++;
}


bool Matrix::isCharInLine(std::string line){
    bool wasSpace = false;
    bool wasMinus = false;

    for(size_t i = 0; i < line.size(); i++){

        if(line[i] == ' ' && !wasSpace){
            wasSpace = true;
            continue;
        }else if(line[i] == ' ' && wasSpace){
            return true;
        }

        if(line[i] == '-' && !wasMinus){
            wasMinus = true;
            continue;
        }else if(line[i] == '-' && wasMinus){
            return true;
        }

        int number = (int)line[i] - (int)'0';
        if(number < 0 || number > 9 ){
           return true; 
        }

        wasMinus = false;
        wasSpace = false;
    }
    return false;
}


void Matrix::loadFromString(std::string matrixString, int x){
    int i = 0;
    this->data->x = i;
    size_t j = 0;

    while( i  < x){
        this->data->x = i+1;
        int y = 1;
        bool notNumber = true;
        bool isNegative = false;
        int value = 0;
        this->data->table[i] = new int[1];

        while(j < matrixString.size()){
            char character= matrixString[j];
            j++;

            if(character == ' ' && notNumber){
                notNumber = false;
                continue;
            }

            if((character == ' ' || character == ';') && !notNumber){
                this->data->table[i][y-1] = value;
                value = 0;
                y++;
                if(character == ' ' ){
                    int* tmp = this->data->table[i];
                    this->data->table[i] = nullptr;
                    this->data->table[i] = new int[y];
                    for(int k = 0; k < y-1; k++){
                        this->data->table[i][k] = (int)tmp[k];
                    }
                    delete[] tmp;

                }
                if(character == ';'){
                    if(i == 0){
                        this->data->y = y-1;
                    }
                    i++;
                    break;
                }
                continue;
            }

            if(character == '-'){
                isNegative = true;
                continue;
            }

            int number = (int)character - (int)'0';
            notNumber = false;

            if(isNegative){
                number = -number;
            }

            if(!notNumber){
                value *=10;
                value += number;
            }

        }

    }
}



Matrix::Matrix(std::string filename){
    std::ifstream file (filename);
    std::string line;
    std::string matrixString ="";
    int x = 0;

    if(file.is_open()){

        if(file.peek() == std::ifstream::traits_type::eof()){
            throw EmptyFile();
        }

        while (std::getline(file, line)){
            if(isCharInLine(line)) throw BadInput();
            matrixString = matrixString  + line + ";";
            x++;
        }

        file.close();
        this->data = new Data(x,0);
        loadFromString(matrixString, x);

    }else{
        throw OpenFileError();
    }
}


Matrix& Matrix::operator*=(const Matrix& other){
    mathOperation(other, '*');
        return *this;

}


Matrix operator*(const Matrix& first, const Matrix& second){
    Matrix result = first;
    result *= second;
    return result;

}

Matrix& Matrix::operator-=(const Matrix& other){
    mathOperation(other, '-');
        return *this;

}


Matrix operator-(const Matrix& first, const Matrix& second){
    Matrix result(first.getX(), first.getY());
    result -= first;
    result -= second;
    return result;

}


Matrix& Matrix::operator+=(const Matrix& other){
    mathOperation(other, '+');
        return *this;
}


Matrix operator+(const Matrix& first, const Matrix& second){
    Matrix result(first.getX(), first.getY());
    result += first;
    result += second;
    return result;

}


void Matrix::mathOperation(const Matrix& other, char choice){
    if(choice != '*'){
        if(this->getX() != other.getX() || this->getY() != other.getY()){
            throw DifferentDimensions();
        }

    }else{
        if(this->getX() != other.getY() || this->getY() != other.getX()){
            std::cout<<this->getX()<<" "<<this->getY()<<" "<<other.getX()<<" "<<other.getY();
            throw MulBadDimensions();
        }
    }

    int x = this->getX();
    int y = this->getY();
    int newY = (choice == '*')? x : y;
    Data * oldData = this->data;
    int** oldTable = this->data->table;
    int refCount = this->data->refCount;
    resetValue(true);
    this->data = new Data(x, newY);

    for(int i = 0; i < x; i++){
        this->data->table[i] = new int[newY];
        if(choice != '*'){
            for(int j = 0; j < y; j++){
                if(choice == '+'){
                    this->data->table[i][j] = oldTable[i][j] + other.data->table[i][j];
                }
                if(choice =='-'){
                    this->data->table[i][j] = oldTable[i][j] - other.data->table[i][j];

                }
            }

        }else{
            for(int j = 0; j < newY; j++){
                int value = 0;
                for(int k = 0; k < y; k++){
                    value += oldTable[i][k] * other.data->table[k][i];
                }
                this->data->table[i][j] = value;
            }
        }

    }
    if(refCount <= 1){
        delete oldData;
    }else{
        oldData = nullptr;
        oldTable = nullptr;
    }

}


Matrix& Matrix::operator=(const Matrix& other){
    if(*this != other){

        if(this->data->refCount == 1){
            delete this->data;
        }else if(this->data->refCount > 1){
            (this->data->refCount)--;
        }

            this->data = other.data;
            (this->data->refCount)++;

        }
        return *this;
   }


bool Matrix::operator!=(const Matrix& other)const{
    if(this->data->x != other.data->x) return true;
    if(this->data->y != other.data->y) return true;

    bool areEqual = true;

    for(int i = 0; i < this->data->x; i++){
        for(int j = 0; j < this->data->y; j++){
            if(this->data->table[i][j] != other.data->table[i][j]){
                areEqual = false;   
            }
        }
    }
    return !areEqual;
}


std::ostream& operator<<(std::ostream& stream, const Matrix& matrix){
    for(int i = 0; i < matrix.getX(); i++){
        for(int j = 0; j < matrix.getY(); j++){
            stream<<matrix.data->getValue(i, j)<<" ";
        }
        stream<<std::endl;

    }
    return stream;
}


bool Matrix::operator==(const Matrix& other)const{
    return !(*this != other);
}


int Matrix::getRefCount(){
    return this->data->refCount;
}


int Matrix::getX() const{
    return this->data->x;
}


int Matrix::getY()const{
    return this->data->y;
}

void Matrix::isOutOfBounds(int x, int y)const{
 if(x > this->data->x || y > this->data->y){
        throw IndexOutOfBonds();
    }

    if( x < 0 || y < 0){
        throw NegativeIndex();
    }

}

int& Matrix::operator()(int x, int y){
    isOutOfBounds(x, y);
    if(this->data->refCount == 1){
    return this->data->table[x][y];

    }else{
        Data * oldData = this->data;
        oldData->refCount--;
        this->data = new Data(*oldData);
        return this->data->table[x][y];
    }
}


int Matrix::operator()(int x, int y)const{
    isOutOfBounds(x, y);
    return this->data->table[x][y];
}


void Matrix::resetValue(bool isMathOperation){
    int refCount = this->getRefCount();
    if(refCount > 1){
        this->data->refCount--;
        this->data = nullptr;
    }else{
        if(isMathOperation){
            this->data = nullptr;
        }else{
            delete this->data;

        }
        
    }
}


Matrix::~Matrix(){
    this->resetValue(false);
}
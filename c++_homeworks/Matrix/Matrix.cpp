#include "Matrix.h"

Cell::Cell(int number){
    this->value = number;
    this->calledBy = nullptr;
}


void Cell::changeTable(int number){
    int x = *(this->calledBy->x);
    int y = *(this->calledBy->y);

    (*this->calledBy->refCount)--;
    Cell** oldTable = this->calledBy->table;
    this->calledBy->newValue(x, y);

    for(int i = 0; i < x; i++){
        this->calledBy->table[i] = new Cell[y];
        for(int j = 0; j < y; j++){
            int value = oldTable[i][j];
            if(oldTable[i][j].calledBy == this->calledBy) value = number;
            this->calledBy->table[i][j] = Cell(value);
        }
    }

    oldTable = nullptr;
    delete[] oldTable;
}


void Cell::operator=(int number){
    if(this->value != number && *this->calledBy->refCount > 1){
        this->changeTable(number);
        
    }else{
        this->value = number;
    }
    this->calledBy = nullptr;
}


Cell::operator int() const{
    return this->value;
}


bool Cell::operator!=(const Cell& other){
    return this->value != other.value;
}

std::ostream& operator<<(std::ostream& stream, const Cell& cell){
    stream<<" "<<cell.value<<" ";
    return stream;
}

Cell::~Cell(){
    this->calledBy = nullptr;
    delete this->calledBy;
}


Matrix::Matrix(int x, int y){ 

    if(x <= 0 || y <= 0){
        throw BadMatrixDeclaration();
    }

    if( x == 1 && y == 1){
        throw InvalidIndex();
    }

    this->table = new Cell* [x];

    for(int i = 0; i < x; i++){
        this->table[i] = new Cell[y];
    }

    this->x = new int(x);
    this->y = new int(y)    ;
    this->refCount = new int(1);
}


Matrix::Matrix(const Matrix& matrix){
    this->table = matrix.table;
    this->x = matrix.x; 
    this->y = matrix.y;
    this->refCount = matrix.refCount;
    (*this->refCount)++;
}


bool Matrix::isCharInLine(std::string line){
    bool wasSpace = false;
    bool wasMinus = false;

    for(int i = 0; i < line.size(); i++){

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
    this->x = new int(i);
    int j = 0;

    while( i  < x){
        delete this->x;
        this->x = new int(i+1);
        int y = 1;
        bool notNumber = true;
        bool isNegative = false;
        int value = 0;
        this->table[i] = new Cell[1];

        while(j < matrixString.size()){
            char character= matrixString[j];
            j++;

            if(character == ' ' && notNumber){
                notNumber = false;
                continue;
            }

            if((character == ' ' || character == ';') && !notNumber){
                this->table[i][y-1].value = value;
                value = 0;
                y++;
                if(character == ' ' ){
                    Cell* tmp = this->table[i];
                    this->table[i] = nullptr;
                    this->table[i] = new Cell[y];
                    for(int k = 0; k < y-1; k++){
                        this->table[i][k].value = (int)tmp[k];
                    }
                    delete[] tmp;

                }
                if(character == ';'){
                    if(i == 0){
                        this->y = new int(y-1);
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
        this->refCount = new int(1);
        this->table = new Cell*[x];
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
    Cell** oldTable = this->table;
    int refCount = *this->refCount;
    resetValue(true);
    newValue(x, newY);

    for(int i = 0; i < x; i++){
        this->table[i] = new Cell[newY];
        if(choice != '*'){
            for(int j = 0; j < y; j++){
                if(choice == '+'){
                    this->table[i][j].value = (int)oldTable[i][j] + (int)other.table[i][j];
                }
                if(choice =='-'){
                    this->table[i][j].value = (int)oldTable[i][j] - (int)other.table[i][j];

                }
            }

        }else{
            for(int j = 0; j < newY; j++){
                int value = 0;
                for(int k = 0; k < y; k++){
                    value += (int)oldTable[i][k] * (int)other.table[k][i];
                }
                this->table[i][j].value = value;
            }
        }

        if(refCount <= 1){
            delete[] oldTable[i];
        }
    }
    if(refCount <= 1){
        delete[] oldTable;
    }else{
        oldTable = nullptr;
    }

}


Matrix& Matrix::operator=(const Matrix& other){
    if(*this != other){

        if(*this->refCount == 1){
                this->deleteTable();
                delete this->refCount;
                delete this->x;
                delete this->y;
                delete[] this->table;
            }else if(*this->refCount > 1){
                (*this->refCount)--;
            }

            this->refCount = other.refCount;
            (*this->refCount)++;
            this->x = other.x;
            this->y = other.y;
            this->table = other.table;

        }
        return *this;
   }


bool Matrix::operator!=(const Matrix& other)const{
    if(*this->x != *other.x) return true;
    if(*this->y != *other.y) return true;

    bool areEqual = true;

    for(int i = 0; i < *this->x; i++){
        for(int j = 0; j < *this->y; j++){
            if(this->table[i][j] != other.table[i][j]){
                areEqual = false;   
            }
        }
    }
    return !areEqual;
}


std::ostream& operator<<(std::ostream& stream, const Matrix& matrix){
    for(int i = 0; i < matrix.getX(); i++){
        for(int j = 0; j < matrix.getY(); j++){
            stream<<matrix.table[i][j]<<" ";
        }
        stream<<std::endl;

    }
    return stream;
}


bool Matrix::operator==(const Matrix& other)const{
    return !(*this != other);
}


int Matrix::getRefCount(){
    return *this->refCount;
}


int Matrix::getX() const{
    return *this->x;
}


int Matrix::getY()const{
    return *this->y;
}


Cell& Matrix::operator()(int x, int y)const{

    if(x > *this->x || y > *this->y){
        throw IndexOutOfBonds();
    }

    if( x < 0 || y < 0){
        throw NegativeIndex();
    }
    
    this->table[x][y].calledBy = this;
    return this->table[x][y];
}


void Matrix::deleteTable(){
   for(int i = 0; i < *this->x; i++){
        delete[] this->table[i];
    }
 
}

void Matrix::resetValue(bool isMathOperation){
    int refCount = this->getRefCount();
    if(refCount > 1){
        this->table = nullptr;
        this->x = nullptr;
        this->y = nullptr;
        (*this->refCount)--;
        this->refCount = nullptr;
    }else{
        if(isMathOperation){
            this->table = nullptr;
        }else{
            this->deleteTable();
            delete[] this->table;

        }
        delete this->x;
        delete this->y;
        delete this->refCount;
    }
}

void Matrix::newValue(int x, int y)const{
    this->x = new int(x);
    this->y = new int(y);
    this->refCount = new int(1);
    this->table = new Cell*[x];

}

Matrix::~Matrix(){
    this->resetValue(false);
}
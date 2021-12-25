#include "Book.h"

Book::Book(){
    name = " ";
    category = " ";
    author = " ";
    pageNumber = 0;
    borrowed = false;

}

Book::Book(std::string name, std::string category, std::string author,
int pageNumber, bool borrowed):
name(name), category(category), author(author), pageNumber(pageNumber),borrowed(borrowed){}

bool Book::operator!=(const Book& other){
    return !(*this==other);
}

bool Book::operator==(const Book& other){
    if(this->name != other.name) return false;
    if(this->category != other.category)return false;
    if(this->author != other.author) return false;
    if(this->pageNumber != other.pageNumber)return false;
    if(this->borrowed != other.borrowed)return false;
    return true;
}

std::ostream& operator<<(std::ostream& stream, const Book& book){
    stream<<"Book { ";
    stream<<"Name: "<<book.name;
    stream<<"Category: "<<book.category;
    stream<<" author: "<<book.author;
    stream<<"pageNumber: "<<book.pageNumber;
    stream<<"is borrowed: "<<book.borrowed;
    return stream;
}


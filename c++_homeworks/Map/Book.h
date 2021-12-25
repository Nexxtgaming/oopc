#pragma once
#include <iostream>

class Book{

public:
    std::string name;
    std::string category;
    std::string author;
    int pageNumber;
    bool borrowed;
    Book();
    Book(std::string name,std::string category, std::string author,
     int pageNumber, bool borrowed);
    bool operator==(const Book& other);
    bool operator!=(const Book& other);
};

std::ostream& operator<<(std::ostream& stream, const Book& book);
#pragma once
#include <iostream>

class Employee{

public:
    std::string name;
    std::string position;
    int age;
    Employee();
    Employee(std::string name, std::string position, int age);
    bool operator==(const Employee& other);
    bool operator!=(const Employee& other);
};

std::ostream& operator<<(std::ostream& stream, const Employee& employee);

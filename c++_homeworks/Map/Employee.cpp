#include "Employee.h"

Employee::Employee(){
    name = " ";
    position = " ";
    age = 0;
}

Employee::Employee(std::string name, std::string position, int age):
name(name), position(position), age(age){}


bool Employee::operator!=(const Employee& other){
    return !(*this==other);
}

bool Employee::operator==(const Employee& other){
    if(this->name != other.name) return false;
    if(this->position != other.position) return false;
    if(this->age != other.age)return false;
    return true;
}

std::ostream& operator<<(std::ostream& stream, const Employee& employee){
    stream<<"Employee { ";
    stream<<"Name: "<<employee.name;
    stream<<"age: "<<employee.age;
    stream<<" position: "<<employee.position;
    return stream;
}


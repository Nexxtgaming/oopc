#include "Poly.h"

Poly::Poly(){
    this->map = {};
}
Poly::Poly(double number){
    std::pair<int, double> newPair(0, number);
    this->map.insert(newPair);
}
double& Poly::operator[](int i ){
    return this->map[i];
}
std::ostream& operator<<(std::ostream& stream, const Poly& poly){
   for(auto itr = poly.map.end(); itr !=poly.map.begin(); --itr){
       int power = itr->first;
       double coefficient = itr->second;
       std::string end = " + ";

         } 
   return stream;
}
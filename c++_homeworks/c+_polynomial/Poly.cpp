#include "Poly.h"

Poly::Poly(){
    std::pair<int, double> newPair(0, 0);
    this->map.insert(newPair);
}
Poly::Poly(double number){
    std::pair<int, double> newPair(0, number);
    this->map.insert(newPair);
}
double& Poly::operator[](int i ){
    return this->map[i];
}
std::ostream& operator<<(std::ostream& stream, const Poly& poly){
    bool isNotAllZero = false;
    for(auto itr = poly.map.rbegin(); itr !=poly.map.rend(); ++itr){
        int power = itr->first;
        double coefficient = itr->second;
        std::string end;
        if(itr == poly.map.rend()){
            end = " ";
        }else{
            end = " + ";
        }
        if(coefficient == 0){
            continue;
        }else{
            isNotAllZero = true;
        }
        if(power == 0){
            stream<<coefficient<<end;
        }else if(power == 1){
            stream<<coefficient<<"x"<<end;
        }
        else{
            stream<<coefficient<<"x^"<<power<<end;
        }
            }
    if(!isNotAllZero){
        stream<<" 0 "<<std::endl;
    }
    
   return stream;
}

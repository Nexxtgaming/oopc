#pragma once
#include <iostream>
template <class T1, class T2>

class Map
{
private:
   T1* keys;
   T2* values;
   int size;


   int getElementIndex(T1 key){
       int index = -1;
       for(int i = 0; i < size; i++){
           if(keys[i] == key)index = i;
       }
       return index;
   }


   void copyTable(Map& map){
       T1* tmp_keys = map.keys;
       T2* tmp_values = map.values;
       if(map == *this){
           this->size++;
       }else{
           delete[] this->keys;
           delete[] this->values;
       }
       keys = new T1[size+1];
       values = new T2[size+1];
       for(int i = 0; i < this->size; i++){
           keys[i] = tmp_keys[i];
           values[i] = tmp_values[i];
       }
       if(map == *this){
           delete[] tmp_keys;
           delete[] tmp_values;

       }
   }

public:

    Map(){
        keys = new T1[1];
        values = new T2[1];
        size=0;
    }


    Map(Map& other){
        this->size = other.size-1;
        this->keys = new T1[this->size];
        this->values = new T2[this->size];
        copyTable(other);

    }

    bool operator==(Map& other){
        if(this->size != other.size)return false;
        if(this->keys == other.keys)return true;
        return false;
    }

    Map& operator=(Map& other){
        this->size = other.size-1;
        copyTable(other);
        return *this;
    }


    void add(T1 key, T2 value){
        if(getElementIndex(key)==-1){
            copyTable(*this);
            keys[size-1] = key;
            values[size-1] = value;

        }else{
            std::cout<<"This key already exist"<<std::endl;
        }
        
    }

    T2* find(T1 key){
        int index = getElementIndex(key);
        if(index == -1){
            std::cout<<"Cannot find"<<std::endl;
            return NULL;
        }
        return &values[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const Map& map){
        stream<<"Map = { ";
        for(int i = 0; i < map.size; i++){
            stream<<"[ "<<map.keys[i]<<" : "<<map.values[i]<<" ] , ";
        }
        stream<<" }";
        return stream;
    }


    ~Map(){
        delete[] keys;
        delete[] values;
    }
};


#include "Hash.h"
#include <iostream>


Hash::Hash(unsigned int size){
    count = 0;
    max_size = size;
    storage = new std::pair<std::string, std::string>[size]; 
}

bool Hash::insert(std::string key, std::string value){
    if(count >= size()){
        return false;
    }

    int offset = 0;
    while(storage[hasher(key)+offset].first != ""){
        offset++;
    }
    std::pair<std::string, std::string> p(key, value);
    storage[hasher(key)+offset] = p;
    return true;
}

//fix to account for collisions later
bool Hash::remove(std::string key){
    if(storage[hasher(key)].first == "")
        return false;
    storage[hasher(key)].first = "";
    storage[hasher(key)].second = "";
    return true;
}

std::string Hash::find(std::string key){
    int index = hasher(key);
    while(storage[index].first != key && index < size()){
        index++;
    }
    if(storage[index].first == key)
        return storage[index].second;
    return "";
}

bool Hash::empty(){
    if(count==0)
        return true;
    return false;
}

int Hash::size(){
    return max_size;
}

void Hash::printHash(){
    for(int i = 0;i<size();i++){
        std::cout<<"Key: " << storage[i].first << ", Value: "<<storage[i].second<<"\n";
    }
}

int Hash::hasher(std::string key){
    int num = 0;
    for(char c: key){
        num+=c;
    }
    return num%size();
}

Hash::~Hash(){
    delete[] storage;
}

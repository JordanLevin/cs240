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
    while(storage[hasher(key)+offset].first != "" && hasher(key)+offset < max_size){
        offset++;
    }
    if(storage[hasher(key)+offset].first == ""){
        std::pair<std::string, std::string> p(key, value);
        storage[hasher(key)+offset] = p;
    }
    for (int i = 0; i < hasher(key); ++i) {
        if(storage[i].first == ""){
            std::pair<std::string, std::string> p(key, value);
            storage[hasher(key)+offset] = p;
            return true;
        }
    } 
    return true;
}

bool Hash::remove(std::string key){
    int offset = 0;
    if(storage[hasher(key)].first == "")
        return false;
    while(storage[hasher(key) + offset].first != key && hasher(key) + offset < max_size){
        offset++;
    }
    if(storage[hasher(key) + offset].first == key){
        storage[hasher(key) + offset].first = "";
        storage[hasher(key) + offset].second = "";
        return true;
    }
    for (int i = 0; i < hasher(key); ++i) {
        if(storage[i].first == key){
            storage[i].first = "";
            storage[i].second = "";
            return true;
        }
    } 
    
    return false;
}

std::string Hash::find(std::string key){
    int index = hasher(key);
    while(storage[index].first != key && index < size()-1){
        index++;
    }
    if(storage[index].first == key)
        return storage[index].second;
    for (int i = 0; i < hasher(key); ++i) {
        if(storage[i].first == key){
            return storage[i].second;
        }
    } 
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
        std::cout<<"Index: " << i << ", Key: " << storage[i].first << ", Value: "<<storage[i].second<<"\n";
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

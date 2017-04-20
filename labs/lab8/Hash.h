#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>
#include <utility>

class Hash{
    private:
        int count;
        int max_size;
        //std::vector<std::string> storage;
        std::pair<std::string, std::string>* storage;
    public:
        Hash(unsigned int size);
        bool insert(std::string key, std::string value);
        bool remove(std::string key);
        std::string find(std::string key);
        bool empty();
        int size();
        void printHash();
        int hasher(std::string key);
        ~Hash();
};

#endif

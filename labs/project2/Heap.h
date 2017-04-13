#ifndef HEAP_H
#define HEAP_H

#include "Player.h"
#include <vector>

class Heap{
    private:
        void heapify();
        void sift(int index);
        std::vector<Player> players;
    public:
        Heap();
        Heap(std::string filename);
        Heap(const Heap &copy);
        void addPlayer(Player newPlayer);
        Player getPlayer();
        std::vector<Player> getArray();
        bool empty();
        unsigned int size();
};

#endif

#ifndef ANTHILL_H
#define ANTHILL_H

#include "LinkedList.h"
#include "Ant.h"
#include <fstream>
#include <iostream>

class AntHill{
    private:
        int current_ants;
        List* ants;
        int next_id;
        int food;
        int gridSize;
        std::ofstream stream;
    public:
        AntHill();
        int addAnt();
        bool removeAnt(int);
        Ant * getAnt(int);
        void move();
        void printHillInfo();
        int getCurrentNumAnts(){return current_ants;}
        int getMaxAnts();
        void turn();
        ~AntHill();
};


#endif

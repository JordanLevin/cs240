#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>


class Player{
    private:
        int budget;
        std::string name;
    public: 
        Card hand;
        Player(std::string name, int b);
        Player();
        std::string getName();
        int getBudget();
        bool bet(int amount);
        void collectWinnings(int amount);
        bool operator> (Player other); 

};

#endif

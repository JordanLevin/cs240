#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include <vector>


class Table{
    public:
        Table(int num_seats, int ante);
        bool emptySeat();
        std::vector<Player> playRound();
        void addPlayer(Player p);
        void printWinner();
};

#endif

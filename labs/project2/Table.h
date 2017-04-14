#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include <vector>


class Table{
    private:
        int seats;
        int ante;
    public:
        Table(int num_seats, int ante);
        bool emptySeat();
        std::vector<Player> playRound();
        void addPlayer(Player p);
        void printWinner();
};

#endif

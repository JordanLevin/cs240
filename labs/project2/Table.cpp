#include "Table.h"
#include <algorithm>
#include "Deck.h"


Table::Table(int num_seats, int ante){
    this->seats = num_seats;
    this->ante = ante;
}

bool Table::emptySeat(){
    if(table.size() < seats)
        return true;
    return false;
}

std::vector<Player> Table::playRound(){
    int money = 0;
    std::vector<Card> cards_drawn;
    Deck cards;
    cards.shuffle();
    for(Player p: table){
        //maybe add check for player balance later
        p.bet(ante);
        money+=ante;
    }
    for(Player p: table){
        p.hand = cards.draw();
        cards_drawn.push_back(p.hand);
    }
    Card winning = *std::max_element(cards_drawn.begin(), cards_drawn.end(),
		[]( const Card &a, const Card &b )
        {
            if(a.value == b.value)
                return a.suit < b.suit;
        	return a.value < b.value;
        }
	);
    std::vector<Player> losers;
    for(Player p: table){
        if(!(p.hand == winning))
            losers.push_back(p);
        else
            winner = p;
    }

    return losers;

}

void Table::addPlayer(Player p){
    table.push_back(p);
}

void Table::printWinner(){

}



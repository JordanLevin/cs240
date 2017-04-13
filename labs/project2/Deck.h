#ifndef DECK_H
#define DECK_H

#include <queue>
#include "Card.h"


class Deck{
	private:
		int size;
        std::queue<Card>* deck;
	public:
		Deck();
		//void print();
		Card draw();
		bool empty();
		void shuffle();
		~Deck();
};

#endif

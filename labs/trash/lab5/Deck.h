#ifndef DECK_H
#define DECK_H

#include "Queue.h"
#include "Card.h"

class Deck{
	private:
		Queue<Card*>* deck;
	public:
		Deck();
		void print();
		Card* draw();
		bool empty();
		void shuffle();
		~Deck();
};

#endif

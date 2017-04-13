#ifndef CARD_H
#define CARD_H

#include <string>

class Card{
	private:
		int value;
		int suit;
	public:
		Card();
		Card(int, int);
		Card(const Card&);
		int getValue();
		int getSuit();
		bool operator==(const Card& other);
		void print();
		//operator std::string() const {
		//	return "value: " +  this->value;
		//}
};

#endif

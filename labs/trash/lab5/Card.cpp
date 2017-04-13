#include "Card.h"
#include <iostream>

Card::Card(){
	value = -1;
	suit = -1;
}
Card::Card(int s, int v){
	value = v;
	suit = s;
}
Card::Card(const Card& original){
	this->value = original.value;
	this->suit = original.suit;
}
int Card::getValue(){
	return value;
}
int Card::getSuit(){
	return suit;
}
bool Card::operator==(const Card& other){
	if(this->value == other.value && this->suit == other.suit){
		return true;
	}
	return false;
}
void Card::print(){
	std::cerr << "Value: " << this->value << ", Suit: "<< this->suit <<std::endl;
}

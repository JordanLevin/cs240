#include "Deck.h"
#include "Card.h"

Deck::Deck(){
	deck = new Queue<Card*>();
	for(int i =1;i<5;i++){
		for(int j=2;j<15;j++){
			Card temp(i,j);
			deck->enqueue(&temp);
		}
	}
}
Card* Deck::draw(){
	return deck->dequeue();
}
bool Deck::empty(){
	if(deck->empty())
		return true;
	return false;
}
void Deck::print(){
	deck->print();
}
void Deck::shuffle(){

}
Deck::~Deck(){
	delete deck;
}

#include "Deck.h"
#include "Card.h"
#include <list>
#include <stdlib.h>

Deck::Deck(){
	size = 52;
	deck = new std::queue<Card>();
	for(int i =1;i<5;i++){
		for(int j=2;j<15;j++){
			Card temp(i,j);
			deck->push(temp);
		}
	}
}
Card Deck::draw(){
	size--;
    Card temp = deck->front();
    deck->pop();
	return temp;
}
bool Deck::empty(){
	if(deck->empty())
		return true;
	return false;
}
void Deck::shuffle(){
    std::list<Card>* arr = new std::list<Card>();
	int temp = size;
	for(int i = 0;i<temp;i++){
		arr->push_back(this->draw());
	}
	while(!arr->empty()){
		Card temp = arr->back();
		if(rand()%10==1){
			deck->push(temp);
			size++;
			arr->remove(temp);
		}

	}
	delete arr;

}
Deck::~Deck(){
	delete deck;
}

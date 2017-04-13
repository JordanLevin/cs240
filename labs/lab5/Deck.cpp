#include "Deck.h"
#include "Card.h"
#include "LinkedList.h"
#include <cstdlib>
#include <time.h>

Deck::Deck(){
	size = 52;
	deck = new Queue<Card>();
	for(int i =1;i<5;i++){
		for(int j=2;j<15;j++){
			Card temp(i,j);
			deck->enqueue(temp);
		}
	}
}
Card Deck::draw(){
	size--;
	return deck->dequeue();
}
bool Deck::empty(){
	if(deck->empty())
		return true;
	return false;
}
//void Deck::print(){
//	deck->print();
//}
void Deck::shuffle(){
	LinkedList<Card>* arr = new LinkedList<Card>();
	int temp = size;
	for(int i = 0;i<temp;i++){
		arr->insert(this->draw());
	}
	//std::cerr<< deck <<std::endl;
	while(!arr->empty()){
		Card temp = arr->read();
		if(rand()%10==1){
			std::cout<<"adding card " << temp.getValue() <<std::endl;
			deck->enqueue(temp);
			size++;
			arr->remove(temp);
		}

	}
	delete arr;

}
Deck::~Deck(){
	delete deck;
}

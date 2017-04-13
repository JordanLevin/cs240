#include "Card.h"

Card::Card(int s, int v){
    suit = s;
    value = v;
}
Card::Card(){
    suit = -1;
    value = -1;
}
bool Card::operator==(const Card& other){
    return other.suit == suit && other.value == value;
}

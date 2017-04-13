#include "Player.h"

Player::Player(std::string n, int b){
    name = n;
    budget = b;
}

std::string Player::getName(){
    return name;
}

int Player::getBudget(){
    return budget;
}

bool Player::bet(int amount){
    budget -= amount;
    return true;
}

void Player::collectWinnings(int amount){
    budget += amount;
}

bool Player::operator>(Player other){
    if(this->getBudget() > other.getBudget())
        return true;
    return false;
}



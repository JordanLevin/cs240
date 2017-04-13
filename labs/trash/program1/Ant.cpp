#include "AntHill.h"
#include <stdlib.h>
#include <iostream>
#include "Ant.h"

//Constructor that takes an id as an int and makes an ant at 0,0 with id that was passed
Ant::Ant(int id1){
    x = 0;
    y = 0;
    id = id1;
    exp = 3;
}

//moves ant's x or y + or - depending on if random value made is 0,1,2,3
void Ant::move(int grid){
    int random = rand()%4;
    if(random==0 && x<=grid){
        x+=1;
    }
    if(random==1 && x>=-grid){
        x-=1;
    }
    if(random==2 && y<=grid){
        y+=1;
    }
    if(random==3 && y>=-grid){
        y-=1;
    }
}

//fight thing for extra credit. The chance of winning is scaled based on the exp. this ant wins if random number is between 1 and its xp, other ant wins if random number is between 'this' ant's xp and this ants xp + other + 1
Ant* Ant::fight(Ant* other){
    std::cout << "Ant #" << this->getID() <<" is fighting Ant #" << other->getID()  << std::endl;
    int random = rand()%(this->exp + other->exp)+1;
    std::cout << "The random number is: " << random << " out of "<<this->exp+other->exp+1 << std::endl;
    if(random<=this->exp){
        std::cout << "Ant " << this->getID() << " wins!" << std::endl;
        this->exp+=other->exp;
        return this;
    }
    else {// if(random>this->exp && random<=(this->exp + other->exp)){
        std::cout << "Ant " << other->getID() << " wins!" << std::endl;
        //other->exp+=this->exp;
        return other;
    }
}

#include <stdlib.h>
#include <iostream>
#include "Ant.h"

Ant::Ant(){
  x = 0;
  y = 0;
  id = -1;
}
//Constructor that takes an id as an int and makes an ant at 0,0 with id that was passed
Ant::Ant(int id1){
    x = 0;
    y = 0;
    id = id1;
}
//copy constructor
Ant::Ant(const Ant& original){
    this->x = original.x;
    this->y = original.y;
    this->id = original.id;
}

//moves ant's x or y + or - depending on if random value made is 0,1,2,3
//doesn't allow ants beyond grid size
void Ant::move(int grid){
    int random = rand()%4;

	if(random==0){
		if(x<=grid)
			x+=1;
		else
			x-=1;
	}
	if(random==1){
		if(x>=-grid)
			x-=1;
		else
			x+=1;
	}
    if(random==2){
		if(y<=grid)
			y+=1;
		else
			y-=1;
	}
	if(random==3){
		if(y>=-grid)
			y-=1;
		else
			y+=1;
	}
}

//2 ants fight, winner is determined by a random value. returns pointer to winning ant
Ant* Ant::fight(Ant* other){
    std::cout << "Ant #" << this->getID() <<" is fighting an enemy ant" << std::endl;
    int random = rand()%10;
    std::cout << "The random number is: " << random << " out of 10"<< std::endl;
    if(random<=5){
        std::cout << "Ant " << this->getID() << " wins!" << std::endl;
        return this;
    }
    else {
        std::cout << "The enemy ant wins!" << std::endl;
        return other;
    }
}

//checks if two ants have all the same values
bool Ant::operator==(Ant other){ //pointer removed
    if(this->id==other.id)
        return true;
    return false;
}

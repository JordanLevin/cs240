#include "AntHill.h"
#include <stdlib.h>
#include <iostream>
#include "Ant.h"
#include "LinkedList.h"
#include <math.h>
#include <cmath>
#include <fstream>


//constructor
AntHill::AntHill(){
    turnCount = 0;
    food = 0;
    current_ants = 0;
    next_id = 0;
    ants = new List();
    this->addAnt();
    this->addAnt();
    this->addAnt();
    stream.open("anthill.log");
    stream << "adding 3 starting ants \n";
	//half the size of the grid. Ants are allowed to get this far from 0 in the x and y
    gridSize = 25;
	attackCount = 0;
	defenseFail = 0;
	defenseSuccess = 0;
}

//creates a new ant and adds it to the anthill
int AntHill::addAnt(){
    current_ants++;
    Ant* ant = new Ant(next_id);
    ants->add(ant);
    next_id++;
    return next_id-1;
}

//removes an ant with a certain id from the ant hill
//returns true on success, false on failure
bool AntHill::removeAnt(int idToRemove){
    if(ants->del(idToRemove)){
        current_ants--;
        return true;
    }
    return false;
}

//returns ant based on id
Ant* AntHill::getAnt(int antId){
    return ants->getById(antId);
}

//performs move() for every ant in anthill
void AntHill::move(){
    stream<<"ants are moving \n";
    for(int i = 0;i<current_ants;i++){
        Ant* temp = ants->get();
        if(temp->getX() < gridSize && temp->getY()<gridSize){
            temp->move(gridSize);
        }
    }
}

//prints info about anthill nicely formatted
void AntHill::printHillInfo(){
    Ant* temp = NULL;
    for(int i = 0;i<current_ants;i++){
        temp = ants->get();
        stream << "Ant #" << temp->getID() << " [" << temp->getX() << "," << temp->getY() << "] \n";
    }
}

//code for each cycle of the anthill
void AntHill::turn(){
    turnCount++;
    stream<<"==================== Turn #" << turnCount << " ====================\n"; 
    stream<< "The Hill currently has:\n";
    stream<< "	Food: "<<food<<"\n";
    stream<< "	Ants: "<<current_ants<<"\n";
	stream<< "The hill has been attacked " << attackCount << " times\n";
	stream<< "Successfully defended: " << defenseSuccess << "\n";
	stream<< "Failed to defend: " << defenseFail << "\n";
	this->printHillInfo();
    Ant* temp = NULL;
    //adds as many ants as food allows
    for(int i =0;i<food;i++){
        this->addAnt();
    }
    stream<<"adding "<<food <<" ants to ant hill \n";
    food = 0;
    this->move();
	
	//%5 is used to produce a 20% chance that attackChance is any specific number
    int attackChance = rand()%5;

    //uses a random number to determine if the anthill is attacked
    //if the hill is attacked all ant's within x distance have id's stored in an array
    int* defenders = new int[current_ants];
    if(attackChance==0){
		attackCount++;
        stream<<"anthill under attack \n";
        int enemyCount = rand()%current_ants+1;
        int defenderCount = 0;

		//stores id of all defending ants in an array
        for(int i = 0;i<current_ants;i++){
            temp = ants->get();
			//calculates all ants within gridSize/2 distance from 0,0
			//I went for a circle around the center because I thought that's what was intended. Don't see a reason to change it
            if( (double) sqrt((double) pow(temp->getX(),(double) 2) + pow((double) temp->getY(),(double) 2)) < gridSize/2){
                std::cout<< temp->getID() << std::endl;
                defenders[i] = temp->getID();
                defenderCount++;
            }
        }

        if(defenderCount>enemyCount){
			defenseSuccess++;
            stream<<"defenders win \n";
        }

        //if the defenders lose every ant with an id in the array created previously is removed
        else{
			defenseFail++;
            stream<<"defenders lose, killing " << defenderCount << " ants  \n";
            for(int i =0;i<defenderCount;i++){
                this->removeAnt(defenders[i]);
            }
			//remove all food from the anthill
			food = 0;
        }

    }
    else{
        stream<<"no attack on anthill this turn \n";
    }
    delete[] defenders;

    //code for fight. makes a temp ant, makes a random number for each ant and if number is 0 starts a fight
    //if the ant in the anthill loses it dies, also has a chance to find food if there is no fight
    Ant* enemy = new Ant(-2);
    for(int i = 0;i<current_ants;i++){
		//%5 is used to produce a 20% chance that encounterChance is any specific number
        int encounterChance = rand()%5;
        temp = ants->get();
        if(encounterChance==0){
            stream<< "Ant # " <<temp->getID() << " is in a fight \n"; 
            if(temp->fight(enemy) == enemy){
                stream<< "Ant # "<<temp->getID() <<" was killed \n";
                this->removeAnt(temp->getID());
            }
            else{
                stream<< "Ant # "<<temp->getID()<< " won the fight \n";
            }
          }
        else if(encounterChance==1){
            food++;
        }
      }
    delete enemy;
    }



//deleted anthill and every ant in it.
AntHill::~AntHill(){
    delete ants;
    stream.close();
}

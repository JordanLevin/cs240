#include "AntHill.h"
#include <stdlib.h>
#include <iostream>
#include "Ant.h"
#include "LinkedList.h"
#include <math.h>
#include <fstream>


//constructor
AntHill::AntHill() : stream("anthill.log", std::fstream::out) {
    food = 0;
    current_ants = 0;
    next_id = 0;
    ants = new List();
    this->addAnt();
    this->addAnt();
    this->addAnt();
    std::cout << "adding 3 starting ants \n";
    //stream("anthill.log", std::fstream::out);
    //value represents how far in positive or negative direction ant can go (so real dimensions are double)
    gridSize = 25;
}

//checks if there is room for more ants, then creates a new ant and adds it
int AntHill::addAnt(){
    current_ants++;
    Ant* ant = new Ant(next_id);
    ants->add(ant);
    next_id++;
    return next_id-1;
}

//removes an ant with a certain id from the ant hill
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

//-------------------------------------make this work with linked list
//performs move() for every ant in anthill
void AntHill::move(){
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
        std::cout << "Ant #" << i << " [" << temp->getX() << "," << temp->getY() << "]" << std::endl;
    }
}

void AntHill::turn(){
    this->printHillInfo();
    //stream<<"testnigkhwnhuj45inuiw45hbuiw45tuibhyugtfrtcghjbgfrdtfyghj \n";
    Ant* temp = NULL;
    for(int i =0;i<food;i++){
        this->addAnt();
        std::cout<<"adding ant to ant hill \n";
    }
    food = 0;
    for(int i =0;i<current_ants;i++){
        ants->get()->move(gridSize);
        std::cout<<"ants are moving \n";
    }
    int attackChance = rand()%5;
    if(attackChance==0){
        std::cout<<"anthill under attack \n";
        int enemyCount = rand()%current_ants+1;
        int defenderCount = 0;
        int defenders[current_ants];
        //consider making this more efficient, remember its all pointers, second for loop maybe not needed
        for(int i = 0;i<current_ants;i++){
            //checks if dist is < 25 using pythagorean thing
            temp = ants->get();
            if( (double) sqrt(temp->getX() + temp->getY()) < gridSize){
                std::cout<< temp->getID() << std::endl;
                defenders[i] = temp->getID();
                defenderCount++;
            }
        }

        if(defenderCount>enemyCount){
            std::cout<<"defenders win \n";
        }
        else{
            //ANT 0 WONT DIE!!!!!
            //if(this->removeAnt(0))
            //    std::cout<<"IOGERNRHOLERNIKE"<<std::endl;

            std::cout<<"defenders lose, killing " << defenderCount << " ants  \n";
            for(int i =0;i<defenderCount;i++){
                this->removeAnt(defenders[i]);
                std::cout<< "CURRENT ANTS: "<<current_ants<<std::endl;
            }
            std::cout<<"\n";
            this->printHillInfo();
            std::cout<<"\n";
        }

    }
    else{
        std::cout<<"no attack on anthill this turn \n";
    }
    Ant* enemy = new Ant(-2);
    for(int i = 0;i<current_ants;i++){
        int encounterChance = rand()%5;
        if(encounterChance==0){
            temp = ants->get();
            if(temp->fight(enemy) != enemy){
                //this->removeAnt(temp->getID());
            }
            else{
                //bug testing code
                //this->printHillInfo();
                std::cerr<<temp->getID()<<std::endl;
                this->removeAnt(temp->getID());
                std::cout<<temp->getID() <<std::endl;
                this->printHillInfo();
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
    for(int i = 0;i<current_ants;i++){
        //std::cout<< ants[i]->getID() << std::endl;
        //delete ants[i];
    }
    delete ants;
    stream.close();
}

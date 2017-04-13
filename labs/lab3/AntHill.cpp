#include "AntHill.h"
#include <stdlib.h>
#include <iostream>
#include "Ant.h"


//constructor
AntHill::AntHill(){
    current_ants = 0;
    next_id = 0;
    ants = NULL;
}

//checks if there is room for more ants, then creates a new ant and adds it
int AntHill::addAnt(){
    current_ants++;
    next_id++;
    Ant ** temp = new Ant*[current_ants];
    for(int i = 0;i<current_ants-1;i++){
        temp[i] = ants[i];
    }
    temp[current_ants-1] = new Ant(next_id);
    delete[] ants;
    ants = temp;
    return next_id;
}

//removes an ant with a certain id from the ant hill
bool AntHill::removeAnt(int idToRemove){
    bool success = false;
    bool contains = false;

    //checks if the id is present
    for(int i = 0;i<current_ants;i++){
        if(ants[i]->getID()==idToRemove){
            contains = true;
        }
    }
    //returns false if the id is not present in the anthill
    if(!contains){
        return false;
    }

    //creates new array 1 smaller and adds all other ants to it
    int counter = 0;
    Ant ** temp = new Ant*[current_ants-1];
    for(int i = 0;i<current_ants;i++){
        if(ants[i]->getID() != idToRemove){
            temp[counter] = ants[i];
            counter++;
        }
        else{
            delete ants[i];
            success =true;
        }

    }

    delete[] ants;
    ants = temp;
    current_ants--;
    return success;
}

//returns ant based on id
Ant* AntHill::getAnt(int antId){
    for(int i =0;i<current_ants;i++){
        if(ants[i]->getID()==antId){
            return ants[i];
        }
    }
    return NULL;
}

//performs move() for every ant in anthill
void AntHill::move(){
    for(int i = 0;i<current_ants;i++){
        ants[i]->move();
    }
}

//prints info about anthill nicely formatted
void AntHill::printHillInfo(){
    for(int i = 0;i<current_ants;i++){
        std::cout << "Ant #" << i << " [" << ants[i]->getX() << "," << ants[i]->getY() << "]" << std::endl;
    }
}

//deleted anthill and every ant in it.
AntHill::~AntHill(){
    for(int i = 0;i<current_ants;i++){
        //std::cout<< ants[i]->getID() << std::endl;
        delete ants[i];
    }
    delete[] ants;
}

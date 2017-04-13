#include "AntHill.h"
#include <stdlib.h>
#include <iostream>

//Constructor with no parameters. sets x,y to 0 and id to -1
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

//moves ant's x or y + or - depending on if random value made is 0,1,2,3
void Ant::move(){
    int random = rand()%4;
    if(random==0){
        x+=1;
    }
    if(random==1){
        x-=1;
    }
    if(random==2){
        y+=1;
    }
    if(random==3){
        y-=1;
    }
}

//returns ant's id
int Ant::getID(){
    return id;
}

//returns ant's x coord
int Ant::getX(){
    return x;
}

//returns ant's y coord
int Ant::getY(){
    return y;
}

//creates new anthill with 0 ants, next_id of 0, and passes in max amount of ants
//next_id is used when adding more ants
AntHill::AntHill(int max){
    current_ants = 0;
    max_ants = max;
    next_id = 0;
}

//checks if there is room for more ants, then creates a new ant and adds it
bool AntHill::addAnt(){
    if(current_ants+1<=max_ants){
        Ant temp(next_id);
        //std::cout << temp.getID() << std::endl;
        ants[current_ants] = temp;
        next_id++;
        current_ants++;
        return true;
    }
    else{
        return false;
    }

}

//returns ant based on index in array
Ant AntHill::getAnt(int index){
    return ants[index];
}

//performs move() for every ant in anthill
void AntHill::move(){
    for(int i = 0;i<current_ants;i++){
        ants[i].move();
    }
}

//changes max amount of ants if value passed in is between 0 and 100
bool AntHill::changeMax(int max){
    if(max >=0 && max <=MAX_ALLOWED){
        max_ants = max;
        return true;
    }
    else{
    return false;
    }
}

//prints info about anthill nicely formatted
void AntHill::printHillInfo(){
    for(int i = 0;i<current_ants;i++){
        std::cout << "Ant #" << i << " [" << ants[i].getX() << "," << ants[i].getY() << "]" << std::endl;
    }
}

//returns current amount of ants
int AntHill::getCurrentNumAnts(){
    return current_ants;
}

//returns max_ants
int AntHill::getMaxAnts(){
    return max_ants;
}


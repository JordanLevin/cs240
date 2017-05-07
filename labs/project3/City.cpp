#include "City.h"
#include <iostream>


City::City(const std::string& cityName, int xCoord, int yCoord)
: name(cityName)
{
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

std::string City::getName(){
    return name;
}

int City::getXCoor(){
    return xCoord;
}

int City::getYCoor(){
    return yCoord;
}

std::list<City*> City::getAdjacent(){
    return adjacent;
}

void City::addAdjacent(City* c){
    adjacent.push_back(c);
}

bool City::operator<(City& c){
    return this->getName() < c.getName();
}

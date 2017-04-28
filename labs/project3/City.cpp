#include "City.h"

City::City(std::string cityName, int xCoord, int yCoord){
    name = cityName;
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

std::string City::getName(){
    return name;
}

int City::getXCoord(){
    return xCoord;
}

int City::getYCoord(){
    return yCoord;
}

std::list<City*> City::getAdjacent(){
    return adjacent;
}

bool City::operator<(City& c){

}

#ifndef CITY_H
#define CITY_H

#include <list>
#include <string>

class City{
    private:
        std::string name;
        int xCoord;
        int yCoord;
        std::list<City*> adjacent; 
    public:
        City(std::string cityName, int xCoord, int yCoord);
        std::string getName();
        int getXCoord();
        int getYCoord();
        std::list<City*> getAdjacent();
        bool operator<(City& c);

};

#endif

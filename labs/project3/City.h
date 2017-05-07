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
        //Values used for dijkstra
        City* previous = nullptr;
        int dist = -1;
        bool explored = false;
        //required by assignment
        City(const std::string& cityName, int xCoord, int yCoord);
        std::string getName();
        int getXCoor();
        int getYCoor();
        std::list<City*> getAdjacent();
        void addAdjacent(City* c);
        bool operator<(City& c);

};

#endif

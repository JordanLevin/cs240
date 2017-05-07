#ifndef MAP_H
#define MAP_H

#include "City.h"
#include <string>
#include <vector>

class Map{
    private:
        std::vector<City> cities;
    public:
        std::vector<City*> shortestPath(City* start, City* dest);
        unsigned int pathDistance(City* start, City* dest);
        Map(std::string filename);
        City* findByName(std::string cityName);
        
        //non mandatory helper functions
        int distance(City* a, City* b);
        City* findLowest();
        
};

#endif

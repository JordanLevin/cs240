#ifndef MAP_H
#define MAP_H

#include "City.h"
#include <string>
#include <vector>

class Map{
    private:
        std::vector<City> cities;
    public:
        Map(std::string filename);
        City* findByName(std::string cityName);
};

#endif

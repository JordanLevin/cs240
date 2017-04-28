#include "Map.h"
#include <fstream>

Map::Map(std::string filename){
    std::string name;
    int x;
    int y;
    std::ifstream input(filename);
    while(!input.eof()){
        input >> name;
        input >> x;
        input >> y;
        City temp(name, x, y);
        cities.push_back(temp);
    }
    for(City c: cities){

    }
    
}

City* Map::findByName(std::string cityName){
    for(int i = 0; i<(int)cities.size();i++){
        if(cities[i].getName() == cityName){
            return &cities[i];
        }
    }
    return nullptr;
}

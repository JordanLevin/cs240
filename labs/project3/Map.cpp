#include "Map.h"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <fstream>
#include <iostream>

Map::Map(std::string filename){
    std::string name;
    int x;
    int y;
    std::ifstream input(filename);
    while(!input.eof()){
        name = "";
        input >> name;
        //small hack to fix issue where beijing got inserted twice
        if(name == ""){
            break;
        }
        input >> x;
        input >> y;
        City temp(name, x, y);
        cities.push_back(temp);
    }

    for(City& c: cities){
        std::vector<City*> sameX;
        std::vector<City*> sameY;
        //generate lists of cities with the same x or y as current city
        for(City& d: cities){
            if(c.getXCoor() == d.getXCoor()){
                sameX.push_back(&d);
            }
            if(c.getYCoor() == d.getYCoor()){
                sameY.push_back(&d);
            }       
        }

        //sort lists based on x and y coords 
        std::sort(sameX.begin(), sameX.end(), 
                [](City* a, City* b) -> bool{
                    return a->getYCoor() > b->getYCoor();
                });
        std::sort(sameY.begin(), sameY.end(), 
                [](City* a, City* b) -> bool{
                    return a->getXCoor() > b->getXCoor();
                });

        //grab the two closest cities on y axis and add them to adjacent list
        for(size_t i = 0;i<sameX.size();i++){
            if(sameX[i] == &c){
                if(i > 0)
                    c.addAdjacent(sameX[i-1]);
                if(i < sameX.size()-1)
                    c.addAdjacent(sameX[i+1]);
                break;
            }
        }
        //grab the two closest cities on x axis and add them to adjacent list
        for(size_t i = 0;i<sameY.size();i++){
            if(sameY[i] == &c){
                if(i > 0)
                    c.addAdjacent(sameY[i-1]);
                if(i < sameY.size()-1)
                    c.addAdjacent(sameY[i+1]);
                break;
            }
        }
    }
}

//returns pointer to city of a specified name
City* Map::findByName(std::string cityName){
    for(City& c: cities){
        if(c.getName() == cityName){
            return &c;
        }
    }
    return nullptr;
}


std::vector<City*> Map::shortestPath(City* start, City* dest){
    //reset the map every time dijkstra's is run
    for(City& c: cities){
        c.dist = -1;
        c.previous = nullptr;
        c.explored = false;
    }
    findByName(start->getName())->dist = 0;
    std::vector<City*> ret;
    //algorithm is completed when the lowest dist in the table is the destination city
    while(findLowest() != dest){
        //return empty vector if lowest is null. this means there is no path
        if(findLowest() == nullptr){
            return ret;
        }
        //explore the closest city
        City* temp = findLowest();
        temp->explored = true;
        for(City* c: temp->getAdjacent()){
            //every distance is better than -1
            if(c->dist == -1){
                c->dist = temp->dist + distance(temp, c);
                c->previous = temp;
                continue;
            }
            //ignore if the city has been fully explored
            if(c->explored)
                continue;
            //ignore if we would be increasing the value of dist
            if(c->dist < temp->dist + distance(temp, c) && temp->dist != -1)
                continue;
            c->dist = temp->dist + distance(temp, c);
            c->previous = temp;
        }
    }
    //jump back until we hit the starting city
    City* i = findLowest();
    while(i != nullptr){
        ret.push_back(i);
        if(i == start)
            break;
        i = i->previous;
    }
    //reverse the list so it goes from start
    std::reverse(ret.begin(), ret.end());
    return ret;
}

//calculates distance between 2 cities. ASSUMES CITIES ARE IN SAME X OR Y AXIS
int Map::distance(City* a, City* b){
    return abs(a->getXCoor() - b->getXCoor()) + abs(a->getYCoor() - b->getYCoor());
}

//returns the city in the list of cities that has the lowest distance value. (-1 is treated as infinity)
//returns nullptr if all cities are explored
City* Map::findLowest(){
    int min = -1;
    City* ret = nullptr;
    for(City& c: cities){
        if(c.dist == -1)
            continue;
        if(min == -1 && !c.explored){
            min = c.dist;
            ret = &c;
            continue;
        }
        if(c.explored)
            continue;
        if(c.dist < min){
            min = c.dist;
            ret = &c;
        }
    }
    return ret;
}

//uses dijkstra's to calculate the distance between two cities
unsigned int Map::pathDistance(City* start, City* dest){
    int ret = 0;
    auto path = shortestPath(start, dest);
    if(path.size() == 0){
        return -1;
    }
    for(size_t i = 0;i<path.size()-1;++i){
        ret+=distance(path[i], path[i+1]);
    }
    return ret;
}

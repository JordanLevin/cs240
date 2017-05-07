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
        input >> name;
        input >> x;
        input >> y;
        City temp(name, x, y);
        cities.push_back(temp);
    }
    //idk why but beijing gets inserted twice, pop it off here
    cities.pop_back();

    for(City& c: cities){
        std::cout << "" << std::endl;
        std::cout << c.getName() << std::endl;
        std::vector<City*> sameX;
        std::vector<City*> sameY;
        for(City& d: cities){
            if(c.getXCoor() == d.getXCoor()){
                sameX.push_back(&d);
            }
            if(c.getYCoor() == d.getYCoor()){
                sameY.push_back(&d);
            }       
        }
        std::sort(sameX.begin(), sameX.end(), 
                [](City* a, City* b) -> bool{
                    return a->getYCoor() > b->getYCoor();
                });
        std::sort(sameY.begin(), sameY.end(), 
                [](City* a, City* b) -> bool{
                    return a->getXCoor() > b->getXCoor();
                });

        for(size_t i = 0;i<sameX.size();i++){
            if(sameX[i] == &c){
                if(i > 0)
                    c.addAdjacent(sameX[i-1]);
                if(i < sameX.size()-1)
                    c.addAdjacent(sameX[i+1]);
                break;
            }
        }
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

City* Map::findByName(std::string cityName){
    for(int i = 0; i<(int)cities.size();i++){
        if(cities[i].getName() == cityName){
            return &cities[i];
        }
    }
    return nullptr;
}


std::vector<City*> Map::shortestPath(City* start, City* dest){
    findByName(start->getName())->dist = 0;
    while(findLowest() != dest){
        if(findLowest() == nullptr){
            std::vector<City*> ret;
            return ret;
        }
        City* temp = findLowest();
        temp->explored = true;
        for(City* c: temp->getAdjacent()){
            //ignore if the city has been fully explored
            if(c->explored)
                continue;
            //ignore if we would be increasing the value of dist
            if(c->dist < temp->dist + distance(temp, c))
                continue;
            c->dist = temp->dist + distance(temp, c);
        }
    }
    std::vector<City*> ret;
    City* i = findLowest();
    while(i != start){
        std::cout << i->getName() << std::endl;
        ret.push_back(i);
        i = i->previous;
    }
    return ret;
    /*using path = std::tuple<City*, City*, int, bool>;
    std::vector<City*> ret;
    std::vector<path> route;
    for(City& c: cities){
        int dist = -1;
        if(&c == start)
            dist = 0;
        route.push_back(std::make_tuple(&c, nullptr, dist, false));
    }
    bool done = false;
    while(!done){
        std::sort(route.begin(), route.end(), 
            [](path a, path b) -> bool{
                if(std::get<3>(a) && !std::get<3>(b))
                    return true;
                if(std::get<3>(b) && !std::get<3>(a))
                    return false;
                if(std::get<2>(a) == -1)
                    return true;
                if(std::get<2>(b) == -1)
                    return false;
                return std::get<2>(a) > std::get<2>(b);
            });
        for(path p: route){
            std::cout << std::get<0>(p)->getName() << std::endl;
        }
        if(std::get<0>(route[0]) == dest){
            done = true;
            break;
        }
        path temp = route[0];
        std::get<3>(temp) = true;
        for(City* city: std::get<0>(temp)->getAdjacent()){
            for(path p: route){
                if(city == std::get<0>(p) && !std::get<3>(p)){
                    std::get<1>(p) = std::get<0>(temp);
                    std::get<2>(p) += distance(std::get<0>(temp), std::get<0>(p));
                }
            }
        }
    }
    path temp = route[0];
    for(path p: route){
        if(std::get<0>(temp) == std::get<0>(p)){
            ret.push_back(std::get<0>(temp));
            temp = p;
        }    
    }
    return ret;*/
}

int Map::distance(City* a, City* b){
    return abs(a->getXCoor() - b->getXCoor()) + abs(a->getYCoor() - b->getYCoor());
}
City* Map::findLowest(){
    int min = -1;
    City* ret = nullptr;
    for(City& c: cities){
        if(c.dist == -1)
            continue;
        if(c.explored)
            continue;
        else if(min != -1 && c.dist < min){
            min = c.dist;
            ret = &c;
        }
        else{
            min = c.dist;
        }
        
    }
    return ret;
}

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

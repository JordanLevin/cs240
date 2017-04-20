#include "Heap.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>

Heap::Heap(){

}

Heap::Heap(std::string filename){
    std::ifstream stream;
	stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        stream.open(filename);
        while(!stream.eof()){
            std::string name;
            std::string budget;
            getline(stream, name);
            getline(stream, budget);
            try {
                Player p(name, std::stoi(budget));
                players.push_back(p);
            }
            catch(std::invalid_argument& e){
                std::cerr << "invalid file \n";
                return;
            }
        }
        stream.close();
    }
    catch (const std::ifstream::failure& e) {
    
    }
    heapify();
}

Heap::Heap(const Heap &copy){
    //std::cout << "Copy Constructor \n";
    for(int i = 0;i<copy.players.size();i++){
        players.push_back(copy.players[i]);
    }
}

void Heap::addPlayer(Player newPlayer){
    players.push_back(newPlayer);
    heapify();
}

Player Heap::getPlayer(){
    Player ret = players[0];
    Player temp = players[players.size()-1];
    players[players.size()-1] = players[0];
    players[0] = temp;
    players.pop_back();
    heapify();
    return ret;
}

std::vector<Player> Heap::getArray(){
    return players;
}

bool Heap::empty(){
    if(size()==0)
        return true;
    return false;
}

unsigned int Heap::size(){
    return players.size();
}

void Heap::heapify(){
    for(int i = (players.size()-2)/2;i>=0;i--){
        sift(i);
    }
}

void Heap::sift(int index){
    int left = 2*index+1;
    int right = 2*index+2;
    if(left >= players.size() || index >= players.size())
        return;
    if(right >= players.size()){
        if(players[left] > players[index]){    
            Player temp = players[left];
            players[left] = players[index];
            players[index] = temp;
            sift(left);
        }
    }
    else if(players[left] > players[right] && players[left] > players[index]){
        Player temp = players[left];
        players[left] = players[index];
        players[index] = temp;
        sift(left);
    }
    else if(players[right] > players[index]){
        Player temp = players[right];
        players[right] = players[index];
        players[index] = temp;
        sift(right);
    }
}

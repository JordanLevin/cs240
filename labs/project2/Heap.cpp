#include "Heap.h"
#include <fstream>
#include <string>

Heap::Heap(){

}

Heap::Heap(std::string filename){
    std::ifstream stream(filename);
    while(!stream.eof()){
        std::string name;
        int budget;
        stream>>name;
        stream>>budget;
        Player p(name, budget);
        players.push_back(p);
    }
}

Heap::Heap(const Heap &copy){

}

void Heap::addPlayer(Player newPlayer){
    players.push_back(newPlayer);
    heapify();
}

Player Heap::getPlayer(){
    Player temp = players[players.size()-1];
    players[players.size()-1] = players[0];
    players[0] = temp;
    Player ret = players.back();
    players.pop_back();
    heapify();
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
    if(left >= players.size())
        return;
    if(players[left] > players[right] && players[left] > players[indexndex]){
        Player temp = players[left];
        players[left] = players[index];
        players[index] = temp;
        sift(left);
    }
    else if(players[right] > players[i]){
        Player temp = players[right];
        players[right] = players[index];
        players[index] = temp;
        sift(right);
    }
}

#include <iostream>
#include <vector>

//it segfaults but the logic is close I think
bool isHeap(int index, std::vector<int> h){
    if(index*2+1 >= h.size())
        return true;
    if(h[index*2+1] > h[index] || h[index*2+2] > h[index])
        return false;
    return isHeap(index*2+1, h) && isHeap(index*2+2, h);
}
int main(){
    std::vector<int> h;
    h.push_back(16);
    h.push_back(9);
    h.push_back(8);
    h.push_back(6);
    h.push_back(10);
    h.push_back(4);
    h.push_back(2);
    h.push_back(1);

    std::cout << isHeap(0, h);
    
}

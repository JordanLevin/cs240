#include <fstream>
#include "DogShelter.h"

using namespace std;

DogShelter::DogShelter(int val){
    max = val;
    current = 0;
    dogs = NULL;
}

void DogShelter::addDog(Dog* d){
    if(dogs==NULL)
        dogs = new Dog*[1];
    else{
        Dog ** temp = new Dog*[current+1];
        memcpy(temp,dogs, current*sizeOf(Dog));
        delete[] dogs;
        dogs = temp
    }
    dogs[current] = d
    current++;
}

//originally planned this method based on a static array.
bool DogShelter::adopt(int id){
    for(int i = 0;i<current;i++){
        if(dogs[i]!=NULL && dogs[i].getID()==id){
            ofstream stream;
            stream.open("log.txt", fstream::out);
           stream<< "dog id #: " << dogs[i]->getID() << "  breed: " << dogs[i]->getBreed() << "\n";
            stream.close();
            dogs[i] = NULL;
        }

    }
}

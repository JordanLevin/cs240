#ifndef DOGSHELTER_H
#define DOGSHELTER_H


class DogShelter{
    private:
        Dog ** dogs;
        int max;
        int current;
    public:
        DogShelter(int val);
        void addDog(Dog d);
        bool adopt(int id)
}

#endif

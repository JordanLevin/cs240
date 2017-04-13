#include "Ant.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node{
    private:
        Node* next;
        Ant* value;
    public:
        Node(Ant* val);
        Ant* getValue();
        void setNext(Node* n);
        Node* getNext();

        ~Node();
};
class List{
    private:
        int size;
        Node* head;
        Node* current;
        Node* currentPos;
    public:
        List();
        List(const List&);
        void add(Ant* ant);
        Ant* get();
        Ant* getById(int id);
        //void insert(Ant* ant);
        bool del(int id);
        void operator<<(Ant* ant);
        void print();

        ~List();
};

#endif

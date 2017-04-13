#include "LinkedList.h"
#include "Ant.h"
#include <iostream>

Node::Node(Ant* val){
    value = val;
    next = NULL;
}
Ant* Node::getValue(){
    return value;
}
void Node::setNext(Node* n){
    next = n;
}
Node* Node::getNext(){
    return next;
}
Node::~Node(){
    delete value;
}



List::List(){
    head = NULL;
    currentPos = head;
    size = 0;
}
List::List(const List& original){
    head = original.head;
}
void List::add(Ant* ant){
    Node* temp = new Node(ant);
    Node* current = head;
    if(head==NULL){
        head = temp;
    }
    else{
        while(current->getNext()!=NULL){
            current = current->getNext();
        }
        current->setNext(temp);
    }
}
//issue with removing ants is here
bool List::del(int id){
    if(head==NULL) return false;

    Node* current = head;
    Node* previous = NULL;
    //should probably add for edge case when list is 1 item
    if(current->getValue()->getID()==id && current->getNext()==NULL){
        delete head;
        head = NULL;
        return true;
    }
    if(current->getValue()->getID()==id){
        current = current->getNext();
        delete head;
        head = current;
        return true;
        
    }
    //end of new changes
    
    while(current->getValue()->getID()!=id){
        if(current->getNext()==NULL){ //changed getValue to getNext
            return false;
        }
        previous = current;
        current = current->getNext();
    }
    previous->setNext(current->getNext());
    delete current;
    return true;


}
//PRETTY SURE THERE IS AN ISSUE HERE
Ant* List::get(){
    if(head==NULL) return NULL;
    if(currentPos==NULL) currentPos = head;

    Node* temp = NULL;
    if(currentPos->getNext()==NULL){
        temp = currentPos;
        currentPos = head;
        return temp->getValue();
    }
    else{
        temp = currentPos;
        currentPos = currentPos->getNext();
        return temp->getValue();
    }
}
//Gets an ant pointer from the LinkedList. Returns null if an id not in the list is passed
Ant* List::getById(int id){
    if(head==NULL){
        return NULL;
    }
    Node* current = head;
    while(current->getValue()->getID()!=id){
        if(current->getNext()!=NULL){
            current = current->getNext();
        }
        else{
            return NULL;
        }
    }
    return current->getValue();
}
void List::print(){
    if(head==NULL){
        return;
    }
    Node* current = head;
    while(current!=NULL){
        std::cout<< "ID: " << current->getValue()->getID() <<std::endl;
        current = current->getNext();
    }
}
//void List::insert(Ant* ant){ insert isnt needed apparently?
    //do stuff here
//}
void List::operator<<(Ant* ant){
    this->add(ant);
}

List::~List(){
    if(head!=NULL){
        Node* next = NULL;
        Node* current = head;
        while(current->getNext()!=NULL){
            next = current->getNext();
            delete current;
            current = next;
        }
        delete current;
    }
        
    }




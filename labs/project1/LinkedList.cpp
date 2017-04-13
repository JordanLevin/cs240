#include "LinkedList.h"
#include "Ant.h"
#include <iostream>

//node constructor
Node::Node(Ant* val){
    value = val;
    next = NULL;
}
//copy constructor for node, work in progressi
Node::Node(const Node& original){
    value = new Ant(*(original.value));
    next = NULL;
}

//basic getters/setters/destructor
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


//list constructor
List::List(){
    head = NULL;
    currentPos = head;
}

//Copy constructor for the linked list
List::List(const List& original){
	if(original.head==NULL)
        this->head=NULL;
    else{
		Node* temp = original.head;
		this->head = new Node(*temp);
        while(temp->getNext()!=NULL){
			       temp = temp->getNext();
             this->add(new Ant(*(temp->getValue())));
        }
    }
    currentPos = original.currentPos;

}

//adds an ant to the linked list by iterating through the list until the next pointer is null, then pointing next to the new node
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

//deletes a node in the list based on the id of the ant that the node's value points to.
//returns true on success and false on failure(such as if id is not in the list)
bool List::del(int id){
    if(head==NULL) return false;

    Node* current = head;
    Node* previous = NULL;
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

    while(current->getValue()->getID()!=id){
        if(current->getNext()==NULL){
            return false;
        }
        previous = current;
        current = current->getNext();
    }
    previous->setNext(current->getNext());
    delete current;
    return true;


}

//iterates through the list storing the current node pointer in currentPos. Each time get is called it moves to the next node, then back to head when it reaches the end of the list
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
//Gets an ant pointer from the LinkedList based on an ant id. Returns null if an id not in the list is passed
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

//prints the id's of every value in every node in the list
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

//adds an ant
void List::operator<<(Ant* ant){
    this->add(ant);
}

//all nodes in the list
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

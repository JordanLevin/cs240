
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <typeinfo>
#include <iostream>

template <class T> class Node{
    private:
        T value;
        Node* next;
    public:
		//this only works when its like this, apparently becausae otherwise c++ tries to use the default constructor. this way it has default values?
        Node(T val) : value(val), next(nullptr) { }

        Node(const Node& original){
            value = original.value;
            next = NULL;
        }
        T& getValue(){
            return value;
        }
        void setNext(Node* n){
            next = n;
        }
        Node* getNext(){
            return next;
        }

};
//forward declare queue so we can friend it
template <class T> class Queue;

template <class T> class LinkedList{
	//friend queue so queue can access the head of the list
	friend class Queue<T>;
	private:
        Node<T>* head;
        Node<T>* currentPos;
    public:
        LinkedList(){
            head = NULL;
            currentPos = head;
        }

		//creates a deep copy of a list 
        LinkedList(const LinkedList& original){
        	if(original.head==NULL)
                this->head=NULL;
            else{
        		Node<T>* temp = original.head;
        		this->head = new Node<T>(*temp);
                while(temp->getNext()!=NULL){
        			       temp = temp->getNext();
                     this->insert(temp->getValue());
                }
            }
            currentPos = original.currentPos;

        }
		
		//inserts a copy of the given object into the list
        void insert(T data){
            Node<T>* temp = new Node<T>(data);
            Node<T>* current = head;
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

		//iterates through the list and returns reference to the items
        T& read(){
            if(currentPos==NULL) currentPos = head;

            Node<T>* temp = NULL;
            if(currentPos->getNext()==NULL){
                temp = currentPos;
                currentPos = head;
		        T& temp2 = temp->getValue();
                return temp2;
            }
            else{
                temp = currentPos;
                currentPos = currentPos->getNext();
		        T& temp2 = temp->getValue();
                return temp2;
            }
        }

		//takes a reference to an instance of T, removes a T thats equal to that from the list
        bool remove(T& data){
			//fails if list is empty
            if(head==NULL) return false;
			
			//handles cases where data is the first element or the list is only 1 element
            Node<T>* current = head;
            Node<T>* previous = NULL;
            if(current->getValue()==data && current->getNext()==NULL){
                delete head;
                head = NULL;
                return true;
            }
            if(current->getValue()==data){
                current = current->getNext();
                delete head;
                head = current;
                return true;

            }
			
			//goes through list until specified item is found, then deletes it and points the previous node to the node after it
            while(!(current->getValue()==data)){
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

        //returns true if the list is empty, false if it isnt
		bool empty(){
          if(head==NULL)
            return true;
          return false;
        }

		//deletes the list and all nodes inside
        ~LinkedList(){
          if(head!=NULL){
              Node<T>* next = NULL;
              Node<T>* current = head;
              while(current->getNext()!=NULL){
                  next = current->getNext();
                  delete current;
                  current = next;
              }
              delete current;
          }

    }
};

#endif

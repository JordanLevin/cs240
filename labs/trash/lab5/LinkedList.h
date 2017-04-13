
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <typeinfo>
#include <iostream>

template <class T> class Node{
    private:
        Node* next;
        T value; //pointer removed
    public:
		//Node() = delete;
        Node(T val){ //pointer removed
            value = val;
            next = NULL;
        }
        Node(const Node& original){
            value = original.value; //pointer removed. is this implicitly using copy constructor???
            next = NULL;
        }
        T& getValue(){ //pointer removed
            return value;
        }
        void setNext(Node* n){
            next = n;
        }
        Node* getNext(){
            return next;
        }

        //~Node(){
            //std::cerr << "Pointer location: " << &value << std::endl;
            //std::cerr << "ID : " << value.getID() << std::endl;
            //delete &value;

        //}
};
template <class T> class Queue;

template <class T> class LinkedList{
  friend class Queue<T>;
 private:
        Node<T>* head;
        Node<T>* currentPos;
    public:
        LinkedList(){
            head = NULL;
            currentPos = head;
        }
        LinkedList(const LinkedList& original){
        	if(original.head==NULL)
                this->head=NULL;
            else{
        		Node<T>* temp = original.head;
        		this->head = new Node<T>(*temp);
                while(temp->getNext()!=NULL){
        			       temp = temp->getNext();
                     this->insert(temp->getValue());//pointer removed
                }
            }
            currentPos = original.currentPos;

        }

        void insert(T data){ //pointer removed
            Node<T>* temp = new Node<T>(data); //will this implicitly call the copy constructor
            Node<T>* current = head;
            if(head==NULL){
                head = temp;
            }
            else{
                while(current->getNext()!=NULL){
                  std::cerr << "cycling through list" << '\n';
                    current = current->getNext();
                }
                current->setNext(temp);
            }
        }
        T& read(){ //changed pointer to reference
            //if(head==NULL) return NULL;
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
        //id is actually a pointer to another instance of the object
        /*T* getById(T* id){
            if(head==NULL){
                return NULL;
            }
            Node<T>* current = head;
            while(!(current->getValue()==id)){
                if(current->getNext()!=NULL){
                    current = current->getNext();
                }
                else{
                    return NULL;
                }
            }
            return current->getValue();
        }*/

        bool remove(T& data){
            if(head==NULL) return false;

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
        void operator<<(T* ant){
            this->insert(ant);
        }
        //needs to be converted to stop using getID
        void print(){
            if(head==NULL){
                std::cerr << "ERROR, HEAD NULL" << std::endl;
                return;
            }
            Node<T>* current = head;
            while(current!=NULL){
                current->getValue()->print();
                current = current->getNext();
            }
        }

        bool empty(){
          if(head==NULL)
            return true;
          return false;
        }
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

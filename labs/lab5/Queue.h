
#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <iostream>

template <class T> class Queue{

private:
    LinkedList<T>* list;
public:
	//constructor, makes a linkedlist which the queue stores stuff in
    Queue(){
      list = new LinkedList<T>;
    }

	//adds item to queue
    void enqueue(T data){
      list->insert(data);
    }

	//removes and returns first item in queue
    T dequeue(){
      T temp = list->head->getValue();
      list->remove(temp);
      return temp;
    }
	
	//returns first item in queue without modifying
    T peek(){
      return list->head->getValue();
    }

	//checks if list is empty
    bool empty(){
      if(list->head == NULL)
        return true;
      return false;
    }

	//deletes all elements
    void clear(){
		while(!this->empty()){
			this->dequeue();
		}
    }
    void print(){
      list->print();
    }
	~Queue(){
		delete list;
	}

};

#endif

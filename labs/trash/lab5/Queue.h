
#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <iostream>

template <class T> class Queue{

private:
    LinkedList<T>* list;
    T* start;
public:
    Queue(){
      list = new LinkedList<T>;
    }
    void enqueue(T data){
      list->insert(data);
    }
    T dequeue(){
      T temp = list->head->getValue();
      list->remove(temp);//why does this work but not the above code
      return temp;
    }
    T peek(){
      return list->head->getValue();
    }
    bool empty(){
      if(list->head == NULL)
        return false;
      return true;
    }
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

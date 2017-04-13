#include "LinkedList.h"
#include "Ant.h"
#include <iostream>


int main(){
List* list = new List();

Ant* ant1 = new Ant(0);
Ant* ant2 = new Ant(1);
Ant* ant3 = new Ant(2);
Ant* ant4 = new Ant(3);
Ant* ant5 = new Ant(4);
Ant* ant6 = new Ant(5);

list->add(ant1);
list->add(ant2);
list->add(ant3);
list->add(ant4);
list->add(ant5);
list->add(ant6);


list->del(0);
list->del(1);
list->del(2);
list->del(3);
list->del(5);

Ant* ant7 = new Ant(7);
Ant* ant8 = new Ant(8);
Ant* ant9 = new Ant(9);

list->add(ant7);
list->add(ant8);
list->add(ant9);

list->get();
list->get();

list->print();

delete list;
return 0;
}


LinkedList** listSplit(LinkedList* list){
    LinkedList* even = new LinkedList();
    LinkedList* odd = new LinkedList();
    
	int count = 0;

	while(!list->lastNode()){
		if(count%2==0){
			even->add(list->get());
		}
		else{
			odd->add(list->get());
		}
		count++;
	}
	
	LinkedList** array = new LinkedList[2];
    array[0] = even;
    array[1] = odd;
    return array;
}

void combine(LinkedList* list){
	this->tail->next = list->head;
	list->head->previous = this->tail;
}




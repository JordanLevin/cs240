#include "LinkedList.h"
#include "string"


int main(){
	LinkedList<string> shopping;
	shopping.insert("eggs");
	shopping.insert("milk");
	shopping.insert("sugar");
	shopping.insert("chocolate");
	shopping.insert("flour");

	for(int i = 0;i<5;i++){
		std::cout<< shopping.read() <<std::endl;
	}
	shopping.remove("flour");
	shopping.insert("coffee");
	for(int i = 0;i<5;i++){
		string& temp = shopping.read();
		if(temp=="sugar")
			temp = "honey";

	}
	shopping.remove("milk");



	return 0;
}

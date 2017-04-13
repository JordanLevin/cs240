#include "string"
#include "vector"

int main(){
	vector<string> shopping;
	shopping.push_back("eggs");
	shopping.push_back("milk");
	shopping.push_back("sugar");
	shopping.push_back("chocolate");
	shopping.push_back("flour");

	for(vector<string>::Iterator iter = shopping.begin();iter<shopping.end();iter++){
		std::cout<< *iter <<std::endl;
	}
	shopping.pop_back();
	shopping.push_back("coffee");
	for(vector<string>::Iterator iter = shopping.begin();iter<shopping.end();iter++){
		if(*iter=="sugar")
			*iter = "honey";
	}
	for(vector<string>::Iterator iter = shopping.begin();iter<shopping.end();iter++){
		if(*iter=="milk")
			shopping.erase(iter);
	}





	return 0;
}

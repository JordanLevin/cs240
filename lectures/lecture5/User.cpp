#include "User.h"

using namespace std;

User::User(string name){
    this->name = new string(name);
}

User::~User(){
    delete name;
}

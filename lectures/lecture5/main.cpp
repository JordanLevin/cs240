#include "User.h"
#include <iostream>

using namespace std;

int main(){
    User * user = new User("Bob");
    delete user;
    return 0;
}

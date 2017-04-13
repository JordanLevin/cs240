#include <string>

class User{
    private:
            std::string * name:
    public:
            User(std::string p){
                name = p;
            }
            std::string getName(){return name;}

            User operator=(User other){
                std:string str=std::string(*other.name);
                return User(str);


            }

            ~User();
};

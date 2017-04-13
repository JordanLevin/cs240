#ifndef ANT_H
#define ANT_H

class Ant{
    private:
        int id;
        int x;
        int y;
        int exp;
    public:
        Ant();
        Ant(int);
        void move();
        //am I doing inline methods right?
        int getID(){return id;}
        int getX(){return x;}
        int getY(){return y;}
        Ant * fight(Ant *);
};


#endif

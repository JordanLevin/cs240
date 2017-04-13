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
        Ant(const Ant&);
        void move(int);
        inline int getID(){return id;}
        inline int getX(){return x;}
        inline int getY(){return y;}
        Ant * fight(Ant *);
        bool operator==(Ant); //pointer removed
};


#endif

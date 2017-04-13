#ifndef CARD_H
#define CARD_H

class Card{
    public:
        int suit;
        int value;
        Card(int s, int v);
        Card();
        bool operator==(const Card& other);
};

#endif

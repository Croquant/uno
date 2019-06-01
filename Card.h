/**
    Card.h
    Definition of a Card object

    @author Maxime Desmet Vanden Stock
    @date   May 2019
*/

#ifndef CARD_H
#define CARD_H

#include <string>

enum Color { black, blue, red, yellow, green }; //All 4 possible card colors + black

class Card
{
    public:
        Card();
        Card(int, Color);
        virtual ~Card();
        int num;    // Stores the number of the card
        Color col;  // Stores the color of the card
        void getName();
        bool operator==(Card const & other) const;
        bool operator!=(Card const & other) const;
};

#endif // CARD_H

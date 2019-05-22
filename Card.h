#ifndef CARD_H
#define CARD_H
#include <string>

// Possible card colors
enum Color { black, blue, red, yellow, green };

// The card has two parameters:
// -a color <Color>
// -a number <int>

class Card
{
    public:
        Card();
        Card(int, Color);
        virtual ~Card();
        int num;
        Color col;
        void getName();
        bool operator==(Card const & other) const;
        bool operator!=(Card const & other) const;

};

#endif // CARD_H

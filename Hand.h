#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include "Deck.h"
#include <vector>

// The hand has a vector of cards
// It can draw a card from a deck
// Or play a card to the bottom of a deck

class Hand
{
    public:
        Hand(Deck *, bool);
        virtual ~Hand();
        bool isComputer;
        bool passTurn = false;
        bool isEmpty();
        void draw(Deck * deck);
        bool play(Deck * deck);

    protected:

    private:
        std::vector<Card> hand;
};

#endif // HAND_H

#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>

// The deck is a vector of cards.
// The players draw cards from the top of the deck.
// The players play following the card at the bottom of the deck
// In that way the deck will never run out of cards

class Deck
{
public:
    Deck();
    virtual ~Deck();
    void shuffle();
    Card draw();
    void add(Card & other);
    Card getNext();

private:
    std::vector<Card> cards;

};

#endif // DECK_H

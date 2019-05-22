#include "Deck.h"
#include "Card.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

// Deck constructor
// Populates the deck with all the UNO cards
Deck::Deck()
{
    // two cards of each color and each number only 1 for 0
    for (int n = 0; n < 2; n++)
    {
        int zeros = 0;
        for (int i = n; i <= 11; i++)
        {
            cards.push_back(Card(i, red));
        }
        for (int i = n; i <= 11; i++)
        {
            cards.push_back(Card(i, blue));
        }
        for (int i = n; i <= 11; i++)
        {
            cards.push_back(Card(i, yellow));
        }
        for (int i = n; i <= 11; i++)
        {
            cards.push_back(Card(i, green));
        }

    }

    // 4 black +4 cards
    for (int i = 0; i < 4; i++)
    {
        cards.push_back(Card(12, black));
    }

    // 4 black ANY cards
    for (int i = 0; i < 4; i++)
    {
        cards.push_back(Card(13, black));
    }

    // Shuffle deck before play
    shuffle();
}

// Default destructor
Deck::~Deck()
{
    //dtor
}

// Shuffles the deck
void Deck::shuffle()
{
    srand (time(NULL));
    // Swap each card with another random card
    for (int i = 0; i < cards.size(); i++)
    {
        int r = rand() % cards.size();
        Card temp;
        temp = cards.at(i);
        cards.at(i) = cards.at(r);
        cards.at(r) = temp;
    }
}
// Return the top for the player to draw and deletes it
Card Deck::draw()
{
    Card c = cards.front();
    cards.erase(cards.begin());
    return c;
}

// Adds a card to the bottom of the deck
void Deck::add(Card & other)
{
    cards.push_back(other);
}

// Return the last card added
Card Deck::getNext()
{
    return cards.back();
}

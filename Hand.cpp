#include "Hand.h"
#include <vector>
#include <iostream>


// Hand constructor
// Draws 7 cards from a deck
Hand::Hand(Deck * deck, bool iscomp)
{
    isComputer = iscomp;
    deck->shuffle();
    for (int i = 0; i < 7; i++)
    {
        draw(deck);
    }
}

// Default destructor
Hand::~Hand()
{
    //dtor
}

// Check if a hand is empty
bool Hand::isEmpty()
{
    return hand.empty();
}

// Draws a card from a deck
void Hand::draw(Deck * deck)
{
    // Get the top card of deck (gets deleted in deck)
    Card c = deck->draw();
    // Push it to the end
    hand.push_back(c);

    // Notify player of the new card
    if (!isComputer)
    {
        std::cout << "You drew the card: ";
        c.getName();
        std::cout << ".\n";
    }
    else
    {
        std::cout << "The computer draws a card.\n";
    }
}

// Play Card event
// return true if a card has been played
// return false if no card has been played
bool Hand::play(Deck * deck)
{
    // Output the cart at the bottom of the deck
    std::cout << "Card on the table: ";
    deck->getNext().getName();
    std::cout << "\n";

    // Check if the player or computer has to pass their turn
    if (passTurn && isComputer)
    {
        std::cout << "The computer passes its turn.\n";
        passTurn = false;
        return false;
    }
    if (passTurn && !isComputer)
    {
        std::cout << "You pass your turn.\n";
        passTurn = false;
        return false;
    }

    // If computer
    // Plays the first card that can be played and returns true
    // Or cannot play, draws a card and returns false
    if (isComputer)
    {
        bool played = false;
        for (int i = 0; i < hand.size(); i++)
        {
            if(hand.at(i) == deck->getNext())
            {
                deck->add(hand.at(i));
                hand.erase(hand.begin() + i);
                played = true;
                std::cout << "The computer plays: ";
                deck->getNext().getName();
                std::cout << ".\n";
                std::cout << "The computer has: (" << hand.size() << ") cards left.\n";
                return true;
                break;
            }
        }
        if (!played)
        {
            std::cout << "The computer cannot play any card.\n";
            draw(deck);
            std::cout << "The computer has: (" << hand.size() << ") cards left.\n";
            return false;
        }
    }

    // IF Player
    // Check for all playable cards
    // IF any playable card ask the player which card to play then return true
    // Or cannot plays, draws a card and return false
    else
    {
        int choice;
        std::cout << "Your cards: (" << hand.size() << ")\n";
        std::vector<Card> playable;
        std::vector<int> ids;
        for (int i = 0; i < hand.size(); i++)
        {
            hand.at(i).getName();
            std::cout << ", ";
            if(hand.at(i) == deck->getNext())
            {
                playable.push_back(hand.at(i));
                ids.push_back(i);
            }
        }
        std::cout << "\n";
        if (playable.empty())
        {
            std::cout << "You cannot play any card.\n";
            draw(deck);
            return false;
        }
        else
        {
            std::cout << "Cards your can play: \n";
            for (int i = 0; i < playable.size(); i++)
            {
                std::cout << i+1 << ":[";
                playable.at(i).getName();
                std::cout << "], ";
            }
            std::cout << "\n";
            while (true) {
                std::cout << "your play -> ";
                std::cin >> choice;
                if (choice-1 >= 0 && choice-1 < playable.size())
                {
                    break;
                }
                else {
                    std::cout << "You cannot play that card, try again.\n";
                }
            }
            deck->add(playable.at(choice-1));
            hand.erase(hand.begin() + ids.at(choice-1));
            std::cout << "\n";
            return true;
        }
    }
}

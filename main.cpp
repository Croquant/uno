#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include <queue>

using namespace std;

// Check if the last card played is a special card (+2,+4,PASS,ANY)
// Make the hand draw or pass
void checkSpecialCard(Deck * deck, Hand * hand)
{
    // Check for +2 cards
    if (deck->getNext().num == 10)
    {
        hand->draw(deck);
        hand->draw(deck);
    }

    // Check for PASS or ANY cards
    else if (deck->getNext().num == 11 || deck->getNext().num == 12)
    {
        hand->passTurn = true;
    }

    // Check for +4 cards
    else if (deck->getNext().num == 13)
    {
        hand->draw(deck);
        hand->draw(deck);
        hand->draw(deck);
        hand->draw(deck);
    }
}

int main()
{
    // Initialize deck
    Deck deck;

    // Title screen
    std::cout << " db    db   d8b   db    .d88b.   \n";
    std::cout << " 88    88   888o  88   .8P  Y8.  \n";
    std::cout << " 88    88   88V8o 88   88    88  \n";
    std::cout << " 88    88   88 V8o88   88    88  \n";
    std::cout << " 88    88   88 V8o88   88    88  \n";
    std::cout << " ~Y8888P'   VP   V8P    `Y88P'   \n";
    std::cout << "_________________________________\n\n";
    std::cout << "The game is starting...\n";
    std::cout << "You draw 7 cards.\n";
    cin.get();

    // Player and Computer draw 7 cards each
    Hand player(&deck, false);
    Hand computer(&deck, true);
    cin.get();

    // Game loop
    // Exit if one of the hand is empty
    while (true)
    {
        // Turn of the computer
        std::cout << "###################\n";
        std::cout << "# COMPUTER'S TURN #\n";
        std::cout << "###################\n";
        // Computer plays, if a card has been played check for special card
        if(computer.play(&deck)) checkSpecialCard(&deck, &player);
        if (computer.isEmpty())
        {
            break;
        }
        cin.get();

        // Turn of the player
        std::cout << "#############\n";
        std::cout << "# YOUR TURN #\n";
        std::cout << "#############\n";
        // if the player played a card check for special card
        if(player.play(&deck)) checkSpecialCard(&deck, &computer);
        if (player.isEmpty())
        {
            break;
        }
        cin.get();
    }

    // Check who is the winner
    if (player.isEmpty())
    {
        std::cout << "Congratulations you won the game!\n";
    }
    else {
        std::cout << "The computer won the game. \n";
    }

    return 0;
}

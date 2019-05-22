#include "Card.h"
#include <iostream>

// Default card constructor
Card::Card() : num(0), col(black)
{

}

// Card constructor with arguments for num and color
Card::Card(int n, Color c) : num(n), col(c)
{

}

// Default Card destructor
Card::~Card()
{
    //dtor
}

// Outputs the name of the card
// in the format NUM(COLOR)
void Card::getName()
{
    std::string out = "";
    switch(num)
    {
    case 0:
        out += "0";
        break;
    case 1:
        out += "1";
        break;
    case 2:
        out += "2";
        break;
    case 3:
        out += "3";
        break;
    case 4:
        out += "4";
        break;
    case 5:
        out += "5";
        break;
    case 6:
        out += "6";
        break;
    case 7:
        out += "7";
        break;
    case 8:
        out += "8";
        break;
    case 9:
        out += "9";
        break;
    case 10:
        out += "+2";
        break;
    case 11:
        out += "PASS";
        break;
    case 12:
        out += "ANY";
        break;
    case 13:
        out += "+4";
        break;
    }
    out += "(";
    switch(col)
    {
    case black:
        out += "ANY";
        break;
    case red:
        out += "RED";
        break;
    case blue:
        out +=  "BLUE";
        break;
    case yellow:
        out += "YELLOW";
        break;
    case green:
        out += "GREEN";
        break;
    }
    out += ")";
    std::cout << out;
}

// operator overloaded to check if a card can be played on top of another
bool Card::operator==(Card const & other) const
{
    return (other.num == num || other.col == col || other.col == black || col == black);
}

// opposition operator
bool Card::operator!=(Card const & other) const
{
    return !(*this == other);
}

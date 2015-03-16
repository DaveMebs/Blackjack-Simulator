//blackjack.h -- defines the classes and methods necessary to construct a blackjack simulator
//Author: David Mebane
//Date Started: 3/14/2015
//
//Contains Shoe, Player and Dealer classes
//Designed to allow for playing a single hand; betting strategies then layered upon this code

#include <cstdlib>
using namespace std;

#include "datastructs.h"

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

enum card{ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack = 10, queen = 10, king = 10};

//Shoe Class Definition
class Shoe
{
    private:
        int numDecks;
        Stack<card> shoe;

    public:
        Shoe(int decks = 1);
        ~Shoe();
        int getDecks() { return numDecks; }
        void setDecks(int decks) { numDecks = decks; }
        void shuffle();
        card dealCard();
        double decksRemaining();

#ifdef DEBUG
        card getCard(int index);
#endif
};

//Player Class Definition
//TODO: Currently only supports single hand. Need to add support for multi hands to enable splitting
class Player
{
    protected:
        LinkedList<card> hand;
    public:
        Player();
        virtual ~Player();
        void addCard(card c);
        LinkedList<card>* getHand();
        void clearHand();
};

//Dealer Class Definition
//Very similar to the Player class. Key difference will be different logic for calculating
//      the next "move" (hit/stand/etc.)
class Dealer : public Player
{
    private:

    public:
        Dealer();
        virtual ~Dealer();
};

//Shoe Class Implementation
Shoe::Shoe(int decks)
{
    numDecks = decks;
}

Shoe::~Shoe()
{
    shoe.~Stack();
}

void Shoe::shuffle()
{
    if(numDecks < 1)
        return;
    
    //first we create an unshuffled shoe with all cards to be used
    LinkedList<card> unshuffled;

    for(int i = 0; i < numDecks; i++)
    {
        //add in all of the cards we can easily enumerate through
        for(int j = 1; j <= 10; j++)
        {
            for(int k = 0; k < 4; k++)
                unshuffled.insertTail(card(j));
        }

        //then we add the face cards
        //3 suits * 4 cards per suit = 12 face cards (J,Q,K)
        for(int j = 0; j < 12; j++)
            unshuffled.insertTail(card(10));
    }

    //randomly pull cards from the unshuffled set and add them to the shoe
    int size;
    while((size = unshuffled.getSize()) > 0)
    {
        shoe.push(unshuffled.at(rand() % size, true));
    }
}

card Shoe::dealCard()
{
    return shoe.pop();
}

double Shoe::decksRemaining()
{
    return shoe.getSize() / 52.0;
}

#ifdef DEBUG
card Shoe::getCard(int index)
{
    Stack<card> tempStack;

    for(int i = 0; i < index; i++)
        tempStack.push(shoe.pop());

    card c = shoe.pop();
    shoe.push(c);

    while(tempStack.getSize() > 0)
        shoe.push(tempStack.pop());

    return c;
}
#endif

//Player Class Implementation
//TODO: Currently only supports single hand. Need to add support for multi hands to enable splitting
Player::Player()
{
}

Player::~Player()
{
    hand.~LinkedList();
}

void Player::addCard(card c)
{
    hand.insertTail(c);
}

LinkedList<card>* Player::getHand()
{
    return &hand;
}

void Player::clearHand()
{
    while(hand.getSize() > 0)
        hand.removeTail();
}

//Dealer Class Implementation
Dealer::Dealer() : Player()
{
}

Dealer::~Dealer()
{
}

#endif

//simulator.cpp -- drives blackjack.cpp and allows for playing and simulating games
//Author: David Mebane
//Date Started: 3/15/2015

#define DEBUG

#include <iostream>
#include <iomanip>
using namespace std;

#include "blackjack.h"
#include "datastructs.h"

#ifndef SIMULATOR_CPP_
#define SIMULATOR_CPP_

//Simulator class is used to keep track of game state
class Simulator
{
    public: enum SimMode{manual, automatic};
 
    private:
        int numDecks;
        SimMode mode;
        LinkedList<Player*> players;
        Dealer dealer;
        Shoe shoe;

    public:
        Simulator(int decks, SimMode m);
        ~Simulator();
        void setDecks(int decks);
        void setMode(SimMode m);
        void setPlayers(int p);
        void shuffleShoe();
        void dealHand();
        void endHand();
        bool needToShuffle();

        void printHand();
        void printShoe();
};

Simulator::Simulator(int decks = 1, SimMode m = manual)
{
    setDecks(decks);
    mode = m;
}

Simulator::~Simulator()
{
    Player* p;
    while(players.getSize() > 0)
    {
        p = players.removeTail();
        delete p;
    }
}

void Simulator::setDecks(int decks)
{
    numDecks = decks;
    shoe.setDecks(decks);
}

void Simulator::setMode(SimMode m)
{
    mode = m;
}

void Simulator::setPlayers(int p)
{
    for(int i = 0; i < p; i++)
        players.insertTail(new Player());
}

void Simulator::shuffleShoe()
{
    shoe.shuffle();
}

void Simulator::dealHand()
{
    for(int i = 0; i < 2; i++)
    {
        for(int i = 0; i < players.getSize(); i++)
        {
            players[i]->addCard(shoe.dealCard());
        }
        dealer.addCard(shoe.dealCard());
    }
}

void Simulator::endHand()
{
    for(int i = 0; i < players.getSize(); i++)
        players[i]->clearHand();
    dealer.clearHand();
}

void Simulator::printHand()
{
    LinkedList<card>* hand;

    cout << "Current Hand:\n";
    for(int i = 0; i < players.getSize(); i++)
    {
        hand = players[i]->getHand();
        cout << "\tPlayer " << i << ": ";
        for(int j = 0; j < hand->getSize(); j++)
            cout << setw(3) << right << card((*hand)[j]);
        cout << endl;
    }

    hand = dealer.getHand();
    cout << "\tDealer:   ";
    for(int j = 0; j < hand->getSize(); j++)
        cout << setw(3) << right << card((*hand)[j]);
    cout << endl;
}

void Simulator::printShoe()
{
    int numCards = 52 * shoe.getDecks();
    int i = 0;

    while(i < numCards)
    {
        cout << setw(7) << "";
        for(int j = 0; j < 10 && i < numCards; j++)
        {
            cout << setw(3) << right << shoe.getCard(i);
            i++;
        }
        cout << endl;
    }
}

bool Simulator::needToShuffle()
{
    //shuffle shoe when less than a deck is remaining
    //this limit is fine unless the number of players is greater than a normal casino table size
    return shoe.decksRemaining() < 1 ? true : false;
}

int main()
{
    Simulator sim;
    int choice, decks, players, hands;

    cout << "##### Welcome to the Blackjack Simulator #####\n\n"
         << "Choose mode: \n"
         << "\t1. Manual\n"
         << "\t2. Simulate\n"
         << "\t3. Quit\n"
         << "Enter selection: ";
    cin >> choice;

    if(choice != 1 && choice != 2)
        return 0;
    sim.setMode(Simulator::SimMode(choice));

    cout << "\nEnter the number of decks to use: ";
    cin >> decks;
    sim.setDecks(decks);

    cout << "\nEnter the number of players at the table: ";
    cin >> players;
    sim.setPlayers(players);

    cout << "\nEnter the number of hands to play: ";
    cin >> hands;

    sim.shuffleShoe();

    cout << "\nInitial shoe contents: \n";
    sim.printShoe();

    for(int i = 0; i < hands; i++)
    {
        cout << "\nHand " << i << ":\n";
        sim.dealHand();
        sim.printHand();
        sim.endHand();
    }
    return 0;
}

#endif

//blackjack_tests.cpp -- contains basic tests verifying that the classes
//defined in blackjack.cpp are valid
//Author: David Mebane
//Date Started: 3/15/2015

#define DEBUG

#include <iostream>
#include <iomanip>
using namespace std;

#include "../blackjack.h"

#ifndef SHOE_TESTS_
#define SHOE_TESTS_

void printShoe(Shoe* s)
{
    int numCards = 52 * s->getDecks();
    int i = 0;

    while(i < numCards)
    {
        cout << setw(7) << "";
        for(int j = 0; j < 10 && i < numCards; j++)
        {
            cout << setw(3) << right << s->getCard(i);
            i++;
        }
        cout << endl;
    }
}

void dealShoe(Shoe* s)
{
    double counter;
    while((counter = s->decksRemaining()) > 0)
    {
        cout << setprecision(3) << setw(6) << left << counter << ":";
        for(int i = 0; i < 10 && s->decksRemaining() > 0; i++)
            cout << setw(3) << right << s->dealCard();
        cout << endl;
    }
}

int main()
{
    Shoe shoe = Shoe(2);
    shoe.shuffle();
    cout << "Shuffled Shoe:" << endl;
    printShoe(&shoe);
    cout << "Dealing Shoe:" << endl;
    dealShoe(&shoe);

    return EXIT_SUCCESS;
}

#endif

//shoe_tests.cpp -- contains basic tests verifying that the Shoe class implemented in blackjack.cpp is valid
//Author: David Mebane
//Date Started: 3/15/2015

#include <iostream>
#include <iomanip>
using namespace std;

#include "../blackjack.cpp"

#ifndef SHOE_TESTS_
#define SHOE_TESTS_

void printShoe(Shoe* s)
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
    cout << "Shoe:" << endl;
    printShoe(&shoe);

    return EXIT_SUCCESS;
}

#endif

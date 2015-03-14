//stack_tests.cpp -- implementation of basic stack testing
//Author: David Mebane
//Date Started: 1/26/2015

#include <iostream>
using namespace std;

#include "datastructs.h"

int main()
{
    Stack<char> s;
    char c;

    do
    {
        cout << "Please enter a letter to add to the stack ('Q' to stop): ";
        cin >> c;
        if(c == 'Q')
            break;
        s.push(c);
    }while(1);

    cout << "The letters entered are: \n";
    while(s.getSize() > 0)
    {
        cout << "\t" << s.pop() << "\n";
    }

    return 0;
}

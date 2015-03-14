//linkedlist_tests.cpp -- misc tests for validating the linked list data structure defined in datastructs.h
//Author: David Mebane
//Date: 1/23/2015

#include <iostream>
using namespace std;

#include "datastructs.h"

void linkedListTests()
{
    LinkedList<int> l;
    int v;

    //add to head
    do
    {
        cout << "Please enter a number to add to the head of the list (-1 to stop): ";
        cin >> v;
        if(v == -1)
            break;
        l.insertHead(v);
    }while(1);

    //add to tail
    do
    {
        cout << "Please enter a number to add to the tail of the list (-1 to stop): ";
        cin >> v;
        if(v == -1)
            break;
        l.insertTail(v);
    }while(1);

    int num = 0;
    //remove from head
    cout << "Enter the number of elements to remove from head: ";
    cin >> num;
    if(num > 0)
    {
        cout << "Removed: ";
        for(int i = 0; i < num-1; i++)
        {
            cout << l.removeHead() << ", ";
        }
        cout << l.removeHead() << "\n";
    }

    //remove from tail
    cout << "Enter the number of elements to remove from tail: ";
    cin >> num;
    if(num > 0)
    {
        cout << "Removed: ";
        for(int i = 0; i < num-1; i++)
        {
            cout << l.removeTail() << ", ";
        }
        cout << l.removeTail() << "\n";
    }

    cout << "The list has " << l.getSize() << " elements.\n";
    cout << "The elements are: \n";
    for(int i = 0; i < l.getSize(); i++)
    {
        cout << '\t' << l[i] << '\n';
    }
}

int main()
{
    cout << "Available tests: \n\t1. Linked List\n\tQ. Exit\n>>";
    int s;
    cin >> s;
    if(s == 1)
        linkedListTests();
    return 0;
}


//linkedlist_tests.cpp -- misc tests for validating the linked list data structure defined in datastructs.h
//Author: David Mebane
//Date: 1/23/2015

#include <iostream>
using namespace std;

#include "../datastructs.h"
void printList(LinkedList<int>* list)
{
    cout << "The list has " << list->getSize() << " elements.\n";
    cout << "The elements are: \n";
    for(int i = 0; i < list->getSize(); i++)
    {
        cout << '\t' << (*list)[i] << '\n';
    }
}

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

    printList(&l);

    char c;
    cout << "Would you like to remove specific items (Y/N)? \n";
    cin >> c;
    if(c != 'y' && c != 'Y')
        return;

    int index;
    while(1)
    {
        cout << "Enter an index to remove (-1 to quit): ";
        cin >> index;
        if(index < 0)
            return;
        if(index >= l.getSize())
            cout << "ERR: Invalid index\n";
        else
        {
            cout << l.at(index, true) << " has been removed from the list.\n";
            printList(&l);
        }
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


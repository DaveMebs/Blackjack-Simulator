//datastructs.h -- basic generic data structures
//Author: David Mebane
//Date Started: 1/23/2015

#ifndef DATASTRUCTS_H_
#define DATASTRUCTS_H_

//Linked List Class Definition
template <class T>
class LinkedList
{
private:
    unsigned int length;

protected:
    class Node
    {
    public:
        Node* next;
        Node* prev;
    
        T value;        
        
        Node(T v = 0) 
        {
            next = nullptr;
            prev = nullptr;
            value = v;
        }
    };

public:
    Node* head;
    Node* tail;

    LinkedList();
    ~LinkedList();
    void insertHead(T v);
    void insertTail(T v);
    T removeHead();
    T removeTail();
    T at(unsigned int index, bool remove = false);
    T operator[] (unsigned int index);
    unsigned int getSize() { return length; }
};

//Linked List Class Implementation
template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    while(head != nullptr)
    {
        this->removeHead();
    }
}

template <class T>
void LinkedList<T>::insertHead(T v)
{
    if(head == nullptr)
    {
        head = tail = new Node(v);
    }
    else
    {
        Node* n = new Node(v);
        n->next = head;
        head->prev = n;
        n->prev = nullptr;
        head = n;
    }
    
    length++;
}

template <class T>
void LinkedList<T>::insertTail(T v)
{
    if(head == nullptr)
    {
        head = tail = new Node(v);
    }
    else
    {
        Node* n = head;
        while(n->next != nullptr)
        {
            n = n->next;
        }
        Node* t = new Node(v);
        n->next = t;
        t->prev = n;
        t->next = nullptr;
        tail = t;
    }
    
    length++;
}

template <class T>
T LinkedList<T>::removeHead()
{
    if(head == nullptr)
        throw "ERR: No value to remove. Head is null.";
    T v = head->value;
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    length--;

    return v;
}

template <class T>
T LinkedList<T>::removeTail()
{
    if(tail == nullptr)
        throw "ERR: No value to remove. Tail is null.";
    T v = tail->value;
    if(tail->prev == nullptr)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    length--;

    return v;
}

//at(index, bool) allows for access and removal of specific indices within the list
//index = the item to check
//remove indicates if the item should be remove from the list. 
//  if remove = false, the value will be returned, but the list will remain unmodified
//

template <class T>
T LinkedList<T>::at (unsigned int index, bool remove)        
{
    if(index >= length)
        throw "ERR: Index greater than the length of the list.";

    Node* n;
    //to handle large lists, we search from whichever end of the list that index is closest to
    if(index < length-index) //index is closer to head than tail
    {
        n = head;
        for(int i = 0; i < index; i++)
            n = n->next;
    }
    else //tail is closer to the desired index
    {
        n = tail;
        for(int i = length-1; i > index; i--)
            n = n->prev;
    }

    T value = n->value;

    if(remove)
    {
        if(index == 0)
            removeHead();
        else if(index == length-1)
            removeTail();
        else
        {
            Node* prev = n->prev;
            Node* next = n->next;
            prev->next = next;
            next->prev = prev;
            delete n;
            length--;
        }
    }

    return value;
}

template <class T>
T LinkedList<T>::operator[] (unsigned int index) 
{
    return this->at(index);
}

//Stack Class Definition
template<class T>
class Stack
{
private:
    LinkedList<T> s;

public:
    Stack();
    ~Stack();
    void push(T v);
    T pop();
    unsigned int getSize();
};

//Stack Class Implementation
template <class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::~Stack()
{
    while(this->getSize() > 0)
    {
        this->pop();
    }
}

template<class T>
void Stack<T>::push(T v)
{
    s.insertHead(v);
}

template<class T>
T Stack<T>::pop()
{
    return s.removeHead(); 
}

template<class T>
unsigned int Stack<T>::getSize()
{
    return s.getSize();
}

#endif

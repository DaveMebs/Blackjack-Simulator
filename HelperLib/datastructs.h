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
        
        Node(T v = 0) //will later move to template
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
    T at(unsigned int i) const;
    T operator[] (unsigned int i) const;
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
        delete tail;
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    length--;

    return v;
}

template <class T>
T LinkedList<T>::at (unsigned int index) const   //can optimize the performance of this by choosing if head or
                                                //tail is closer to the desired index
{
    if(index >= length)
        throw "ERR: Index greater than the length of the list.";

        Node* n = head;
    for(int i = 0; i < index; i++)
    {
        n = n->next;
    }
    return n->value;
}

template <class T>
T LinkedList<T>::operator[] (unsigned int index) const 
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

#pragma once

struct elem
{
    int value;
    int index;
};

struct Node
{
    elem value;
    Node* next;
};


Node* createNode(elem value);

class Stack
{
private:
    Node* head;
public:
    Stack();
    Stack(Node* headOther);
    ~Stack();
    void append(elem value);
    void remove();
    int stackLen();
    elem getHead();
    bool stackIsEmpty();
    void print();
};
#pragma once
#include <iostream>

template<typename T>
class List
{
private:
    struct Node
    {
        T value;
        Node* next;
    };
    Node* head;
    void freeList();
public:
    List();
    ~List();
    void append(T value);
    void print();
};

template<typename T>
List<T>::List(){
    head=nullptr;
}

template<typename T>
List<T>::~List(){
    freeList();
}

template<typename T>
void List<T>::freeList(){
    if(head!=nullptr){
        Node* curr = head;
        Node* temp;
        while(curr!=nullptr){
            temp = curr;
            curr=curr->next;
            delete temp;
        }
    }
}

template<typename T>
void List<T>::append(T value){
    Node* newNode = new Node;
    newNode->next=nullptr;
    newNode->value=value;
    if(head==nullptr){
        head = newNode;
        return;
    }
    Node* curr = head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next = newNode;
}

template<typename T>
void List<T>::print(){
    if(head==nullptr){
        return;
    }
    Node* curr = head;
    while(curr!=nullptr)
    {
        std::cout << curr->value << ' ';
        curr = curr->next;
    }
    std::cout << '\n';
}
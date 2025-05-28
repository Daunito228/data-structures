#pragma once
#include <iostream>
#include <stdexcept> //out_of_range с этим робит

template<typename T>
class List
{
private:
    struct Node
    {
        T value;
        Node* next;
        Node* prev;
    };
    Node* head;
    std::size_t sz;
    void freeList();
    Node* getNode(size_t index);
public:
    List();
    ~List();
    void append(T value);
    void print();
    size_t getSize();
    T at(size_t index);
    void removeNode(size_t index);
};

//
//Realization of List
//
template<typename T>
List<T>::List(){
    head=nullptr;
    sz=0;
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
    newNode->prev=nullptr;
    newNode->next=nullptr;
    newNode->value=value;
    sz++;
    if(head==nullptr){
        head = newNode;
        return;
    }
    Node* curr = head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next = newNode;
    newNode->prev=curr;
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

template<typename T>
size_t List<T>::getSize(){
    return sz;
}

template<typename T>
T List<T>::at(size_t index){
    return getNode(index)->value;
}

template<typename T>
typename List<T>::Node* List<T>::getNode(size_t index){
    if (index >= sz) {
        throw std::out_of_range("Index " + std::to_string(index) + " is out of range");
    }
    Node* curr = head;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr;
}

template<typename T>
void List<T>::removeNode(size_t index){
    if (index >= sz) {
        throw std::out_of_range("Index " + std::to_string(index) + " is out of range");
    }
    Node* curr = head;
}
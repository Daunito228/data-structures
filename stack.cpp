#include "stack.hpp"
#include <iostream>

Node* createNode(elem value){
    Node* newNode = new Node;
    newNode->next=nullptr;
    newNode->value=value;
    return newNode;
}

Stack::Stack(){
    head = nullptr;
}

Stack::~Stack(){
    Node* curr = head;
    Node* temp;
    while(curr!=nullptr){
        remove();
    }
}

Stack::Stack(Node* headOther){
    Node* curr = head;
    Node* currOther = headOther;
    while(headOther!=nullptr){
        curr->next = createNode(currOther->value);
        currOther = currOther->next;
        curr = curr->next;
    }
}

void Stack::append(elem value){
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void Stack::remove(){
    if(stackIsEmpty()){
        printf("Stack is empty!\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void Stack::print(){
    Node* curr = head;
    while(curr!=nullptr){
        printf("[index: %d | value: %d]", curr->value.index, curr->value.index);
        if(curr->next!=nullptr){
            printf("->");
        }
        curr = curr->next;
    }
}

int Stack::stackLen(){
    Node* curr = head;
    int len=0;
    while(curr!=nullptr){
        len++;
        curr=curr->next;
    }
    return len;
}

bool Stack::stackIsEmpty(){
    if(head){
        return false;
    }
    return true;
}

elem Stack::getHead(){
    if(!stackIsEmpty()){
        return head->value;
    }
    printf("Stack is empty!\n");
    elem ret;
    ret.index=-1;
    ret.value=0;
    return ret;
}
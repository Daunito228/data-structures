#pragma once

template<typename T>
class Stack
{
private:
    struct Node
    {
        T value;
        Node* next;
    };
    Node* head;
public:
    Stack();
    ~Stack();
    void append(T value);
    void remove();
    int stackLen();
    T getHead();
    bool stackIsEmpty();
};

template<typename T>
Stack<T>::Stack(){
    head = nullptr;
}

template<typename T>
Stack<T>::~Stack(){
    while(head!=nullptr){
        remove();
    }
}

template<typename T>
void Stack<T>::append(T value){
    Node* newNode = new Node;
    newNode->next=nullptr;
    newNode->value=value;
    newNode->next = head;
    head = newNode;
}

template<typename T>
void Stack<T>::remove(){
    if(stackIsEmpty()){
        printf("Stack is empty!\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

template<typename T>
int Stack<T>::stackLen(){
    Node* curr = head;
    int len=0;
    while(curr!=nullptr){
        len++;
        curr=curr->next;
    }
    return len;
}

template<typename T>
bool Stack<T>::stackIsEmpty(){
    if(head){
        return false;
    }
    return true;
}

template<typename T>
T Stack<T>::getHead(){
    if(!stackIsEmpty()){
        return head->value;
    }
    printf("Stack is empty!\n");
    T ret;
    return ret;
}
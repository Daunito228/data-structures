#pragma once
#include <iostream>

template<typename T>
class Vector
{
private:
    T* arr;
    std::size_t sz;
    std::size_t capp;
public:
    Vector();
    Vector(size_t n, T value=static_cast<T>(NULL));
    ~Vector();
    T& operator[](size_t index);
    Vector& operator=(const Vector& other);
    void resize(size_t n, bool rewrite=false, T value=static_cast<T>(NULL));
    void reserve(size_t n); //хуйня чтобы память перевыделять если не хватает в resize()
    T& at();
    void push_back();
    void pop_back();
    bool isEmpty();
    void clear();
    void erase(size_t index);
    void insert(size_t index);
    void print();
    size_t getSize();
    size_t getCapp();
};

template<typename T>
Vector<T>::Vector(){
    arr=nullptr;
    sz=0;
    capp=1;
}

template<typename T>
Vector<T>::Vector(size_t n, T value){
    arr = new T[n];
    sz=n;
    capp=n;
    for(size_t i=0;i<capp;i++){
        arr[i]=value;
    }
}

template<typename T>
Vector<T>::~Vector(){
    if(arr!=nullptr){
        delete[] arr;
    }
}

template<typename T>
T& Vector<T>::operator[](size_t index){
    if(index >= sz){
        throw std::out_of_range("Index " + std::to_string(index) + " is out of range");
    }
    return arr[index];
}

/*template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other){
    if(this==&other){
        return *this;
    }
    return *this;
}*/

template<typename T>
void Vector<T>::reserve(size_t n){
    T* newarr = new T[n];
    for(size_t i=0;i<sz;i++){
        newarr[i]=arr[i];
    }
    delete[] arr;
    arr = newarr;
    capp=n;
}

template<typename T>
void Vector<T>::resize(size_t n, bool rewrite, T value){
    if(n>capp){
        reserve(n);
    }
    for(size_t i=sz;i<capp;i++){
        arr[i]=value;
    }
    if(rewrite){
        sz = capp;
    }
}

template<typename T>
size_t Vector<T>::getSize(){
    return sz;
}

template<typename T>
size_t Vector<T>::getCapp(){
    return capp;
}

template<typename T>
void Vector<T>::print(){
    if(arr==nullptr){
        std::cout<<"[]\n";
        return;
    }
    std::cout << '[';
    for(size_t i=0;i<sz;i++){
        std::cout << arr[i];
        if(i!=sz-1){
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

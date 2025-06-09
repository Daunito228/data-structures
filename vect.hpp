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
    Vector(size_t n, const T& value = T());
    ~Vector();
    T& operator[](size_t index);
    Vector& operator=(const Vector& other);
    void resize(size_t n, const T& value = T());
    void reserve(size_t n); //хуйня чтобы память увеличивать вектор по capp
    T& at();
    void push_back(const T& value);
    void pop_back();
    bool isEmpty();
    void clear();
    Vector conc(const Vector& other);
    void erase(size_t index);
    void insert(size_t index, const T& value);
    void print();
    size_t getSize();
    size_t getCapp();
};

template<typename T>
Vector<T>::Vector(){
    arr=new T[1];
    sz=0;
    capp=1;
}

template<typename T>
Vector<T>::Vector(size_t n, const T& value){
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

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other){
    if(this==&other){
        return *this;
    }
    delete[] arr;
    arr = new T[capp];
    sz = other.sz;
    capp = other.capp;
    for(size_t i=0; i<sz;i++){
        arr[i]=other.arr[i];
    }
    return *this;
}

template<typename T>
void Vector<T>::reserve(size_t n){
    if(capp>=n){
        return;
    }
    T* newarr = new T[n];
    for(size_t i=0;i<sz;i++){
        newarr[i]=arr[i];
    }
    delete[] arr;
    arr = newarr;
    capp=n;
}

template<typename T>
void Vector<T>::resize(size_t n, const T& value){
    if(n>capp){
        reserve(n);
    }
    for(size_t i=sz;i<n;i++){
        arr[i]=value;
    }
    if(n<sz){
        sz=n;
    }
}

template<typename T>
void Vector<T>::push_back(const T& value){
    if(sz==capp){
        reserve(capp*2);
    }
    arr[sz]=value;
    sz++;
}

template<typename T>
void Vector<T>::pop_back(){
    if(sz>0){
        sz--;
    }
}

template<typename T>
void Vector<T>::insert(size_t index, const T& value){
    if(index>=sz){
        return;
    }
    if(sz==capp){
        reserve(capp*2);
    }

    T temp=arr[index];
    for(size_t i=sz;i>index;i--){
        arr[i] = arr[i-1];
    }
    arr[index]=value;
    sz++;
}

template<typename T>
Vector<T> Vector<T>::conc(const Vector& other){
    size_t newCapp=0;
    if(std::max(capp, other.capp) > sz + other.sz){
        newCapp = std::max(capp, other.capp);
    }
    else{
        newCapp = sz+other.sz+1;
    }
    Vector vecNew(newCapp);
    vecNew.sz = sz+other.sz;
    for(size_t i=0;i<sz;i++){
        vecNew.arr[i] = arr[i];
    }
    for(size_t i=0;i<other.sz;i++){
        vecNew.arr[sz+i] = other.arr[i];
    }
    return vecNew;
}

template<typename T>
void Vector<T>::clear(){
    delete[] arr;
    arr = new T[1];
    sz=0;
    capp=1;
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
bool Vector<T>::isEmpty(){
    return sz==0;
}

template<typename T>
void Vector<T>::print(){
    std::cout << '[';
    for(size_t i=0;i<sz;i++){
        std::cout << arr[i];
        if(i!=sz-1){
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

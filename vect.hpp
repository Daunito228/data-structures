#pragma once
#include <iostream>

template<typename T>
class Vector
{
private:
    T* arr;
    std::size_t size;
    std::size_t capp;
public:
    Vector();
    ~Vector();
};
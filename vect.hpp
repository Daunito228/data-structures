#pragma once
#include <iostream>

class Vector
{
private:
    int* arr;
    std::size_t size;
    std::size_t capp;
public:
    Vector();
    ~Vector();
};
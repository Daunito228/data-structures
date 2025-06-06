#include <iostream>
#include "stack.hpp"
#include "vect.hpp"
#include "list.hpp"
#include <vector>
using namespace std;

int main()
{
    Vector<int> vec1(3, 2), vec2(5, 1), vec3;
    vec1.print();
    vec1.resize(20, true, 555);
    vec1.print();
    cout << vec1.getSize() << ' ' << vec1.getCapp() << '\n';
}

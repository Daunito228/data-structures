#include <iostream>
#include "stack.hpp"
#include "vect.hpp"
#include "list.hpp"
#include <vector>
using namespace std;

int main()
{
    Vector<int> vec1(3, 2), vec2(5, 1), vec3, vec4;
    vec1.print();
    vec1.resize(10);
    vec1.print();
    cout << vec1.getSize() << ' ' << vec1.getCapp() << '\n';
    vec2.print();
    cout << vec2.getSize() << ' ' << vec2.getCapp() << '\n';
    vec2 = vec1;
    vec2.print();
    cout << vec2.getSize() << ' ' << vec2.getCapp() << '\n';
    cout << vec4.getSize() << ' ' << vec4.getCapp() <<'\n';
    if(vec4.isEmpty()){
        cout << "sdfsdfsdfsdf";
    }
    vec4.print();
    for(size_t i=3; i<50;i++){
        vec4.push_back(i);
        cout << vec4.getSize() << ' ' << vec4.getCapp() << '\n';
    }
    vec4.print();
    for(size_t i=vec4.getSize();i>10;i--){
        vec4.pop_back();
    }
    vec4.print();
    cout << vec4.getSize() << ' ' << vec4.getCapp() << '\n';
    vec4.push_back(123);
    vec4.print();
    cout << vec4.getSize() << ' ' << vec4.getCapp() << '\n';
    vec4.resize(4);
    vec4.print();
    cout << vec4.getSize() << ' ' << vec4.getCapp() << '\n';
    vec4.insert(2, 123123);
    vec4.print();
    cout << vec4.getSize() << ' ' << vec4.getCapp() << '\n';
}

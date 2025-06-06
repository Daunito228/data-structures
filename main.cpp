#include <iostream>
#include "stack.hpp"
#include "vect.hpp"
#include "list.hpp"
#include <vector>
using namespace std;

int main()
{
    List<int> list;
    int num;
    int maxNum=-__INT_MAX__;
    for(int i=0;i<10;i++){
        cout << i << ") Enter: ";
        cin >> num;
        list.append(num);
    }
    //list.print();
    List<int>* sorted = new List<int>;
    sorted = list.sorted();
    sorted->print();
    list.print();
    return 0;
}

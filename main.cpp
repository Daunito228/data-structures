#include <iostream>
#include "stack.hpp"
#include "vect.hpp"
#include "list.hpp"
#include <vector>
using namespace std;

int main()
{
    List<int> list, sorted;
    int num;

    for(int i=0;i<10;i++){
        cout << i << ") Enter: ";
        cin >> num;
        list.append(num);
    }


    num = list.at(2);
    cout << num << '\n';
    return 0;
}

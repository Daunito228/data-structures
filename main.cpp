#include <iostream>
#include "stack.hpp"

int main()
{
    Stack stack;
    int temp[] = {13, 12, 15, 11, 9, 12, 16};
    int res[7] = {0};
    int len = 7;
    elem elem;
    for(int i=len;i>-1;i--){
        elem.index = i;
        elem.value=temp[i];
        if(stack.stackIsEmpty()){
            stack.append(elem);
        }
    }
    return 0;
}

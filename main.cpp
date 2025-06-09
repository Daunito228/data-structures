#include <iostream>
#include "stack.hpp"
#include "vect.hpp"
#include "list.hpp"
#include <vector>
using namespace std;

int summ(Vector<int>& arr){
    if(arr.getSize()==1){
        return arr[0];
    }
    Vector<int> newarr(arr.getSize()-1);
    for(size_t i=1;i<arr.getSize();i++){
        newarr[i-1] = arr[i];
    }
    return arr[0] + summ(newarr);
}

int main(){
    Vector<int> arr(4, 1), arr1(10);
    for(int i=0;i<5;i++){
        arr1[i]=i;
    }
    Vector<int> arrRes = arr.conc(arr1);
    arrRes.print();
    cout << arrRes.getSize() << ' '<< arrRes.getCapp() << '\n';
}

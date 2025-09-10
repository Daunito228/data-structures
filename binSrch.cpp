#include <iostream>
using namespace std;


int main()
{
    int arr[11];
    int num = 222;
    int low=0, high=10, res=-1;
    int mid;
    for(int i=0;i<11;i++){
        arr[i] = i*2;
    }
    while(high>=low){
        mid = (high+low)/2;
        if(arr[mid]==num){
            res = mid;
            break;
        }
        else if(arr[mid]>num){
            high = mid-1;
        }
        else{
            low=mid+1;
        }
        cout << high << ' ' << low << ' ' << mid << '\n';
    }
    cout << res << '\n';
    return 0;
}

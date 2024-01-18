// Binary Search
#include <iostream>
using namespace std;
int main() {
    int a[10]={2,4,6,8,10,12,14,16,18,20};
    int begin=0,end=9, n=17;
    bool flag=false;
    while(begin<=end){
        int mid=begin + (end-begin)/2;
        if(a[mid]==n){
            cout<<"at "<<mid;
            flag=true;
            break;
        }
        if(a[mid]<n){
            begin=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if (!flag){
        cout<<"not found";
    }
    return 0;
}

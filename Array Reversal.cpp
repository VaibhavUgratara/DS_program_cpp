// Array Reversing
#include <iostream>
using namespace std;
void swap (int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
int main() {
    int len=9;
    int a[len]={1,2,3,4,5,6,7,8,9};
    int l=0,r=len-1;
    while(l<r){
        swap(a[l],a[r]);
        l++;
        r--;
    }
    for(int i=0;i<len;i++){
        cout<<"Element at "<<i<<"th position: "<<a[i]<<endl;
    }
    return 0;
}

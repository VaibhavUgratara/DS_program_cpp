// Bubble Sort
#include <iostream>
using namespace std;
void swap (int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

int main() {
    int len=9;
    int a[len]={2,4,6,7,8,1,3,9,5};
    for(int i=0;i<len-1;i++){
       bool flag=false;
        for(int j=0;j<len-i-1;j++){
            if(a[j+1]<a[j]){
                swap (a[j+1],a[j]);
                flag=true;
            }
        }
        if(!flag){
            break;
        }
    }
    for(int i=0;i<len;i++){
        cout<<"Element at "<<i<<"th position: "<<a[i]<<endl;
    }
    return 0;
}

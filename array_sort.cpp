#include <iostream>
using namespace std;
int main() {
    int l=5;
    int arr[l]={43,4,6,8,9};
    for(int i=0;i<l-1;i++){
        int key=arr[i+1];
        for(int j=i;j>=0;j--){
            if(key<arr[j]){
                arr[j+1]+=arr[j];
                arr[j]=arr[j+1]-arr[j];
                arr[j+1]=arr[j+1]-arr[j];
            }
            else{
                break;
            }
        }
    }
    for (int i=0;i<l;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

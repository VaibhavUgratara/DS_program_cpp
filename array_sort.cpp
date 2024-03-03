#include <iostream>
using namespace std;
int main() {
    int l=5;
    int arr[l]={10,9,83,7,1};
    for(int i=0;i<l-1;i++){
        int key=arr[i+1];
        for(int j=i;j>=0;j--){
            if(key<arr[j]){
                arr[j+1]=arr[j];
                arr[j]=key;
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

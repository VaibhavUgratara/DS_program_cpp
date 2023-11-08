#include<iostream>
using namespace std;
int main(){
    int arr1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr2[3][3]={{9,8,7},{6,5,4},{3,2,1}};
    int arr3[3][3];


    int r=sizeof(arr1)/sizeof(arr1[0]);
    int c=sizeof(arr1[0])/sizeof(int);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr3[i][j]=arr1[i][j]+arr2[i][j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

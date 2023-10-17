#include<iostream>
using namespace std;

//insertion
void arr_insert(int a[],int *s,int n,int i){
    if(i>*s){
        cout<<"Overflow"<<endl;
    }
    else{
        int j=*s;
        for(j; j>=i ; j--){
            if(j==i){
                a[i]=n;
                break;
            }
            a[j]=a[j-1];
        }
        *s+=1;
    }
}

//deletion
void arr_delete(int a[],int *s,int i){
    if(*s==0){
        cout<<"Underflow"<<endl;
    }
    else{
        for(int j=i;j<(*s)-1;j++){
            a[j]=a[j+1];
            if(j==(*s)-2){
                a[j+1]=0;
            }
        }
        *s-=1;
    }
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[100],n1,i1;
    for(int i=0;i<n;i++){
        cout<<"Element at index "<<i<<" : ";
        cin>>arr[i];
    }
    cout<<"Enter data you want to insert: ";
    cin>>n1;
    cout<<"Enter index: ";
    cin>>i1;
    int i;
    arr_insert(arr,&n,n1,i1);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter index of data to delete: ";
    cin>>i1;
    arr_delete(arr,&n,i1);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
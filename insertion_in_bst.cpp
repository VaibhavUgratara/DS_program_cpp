#include<iostream>
using namespace std;

int tree[30];


//funtion to insert an element in a binary search tree
void insertion_in_tree(int data,int i=0){
    if(tree[i]=='\0'){
        tree[i]=data;
    }
    else{
        if(tree[i]<data){
            insertion_in_tree(data,2*i+2);
        }
        else{
            insertion_in_tree(data,2*i+1);
        }
    }
}


int main(){
    insertion_in_tree(10);
    insertion_in_tree(12);
    insertion_in_tree(5);
    insertion_in_tree(4);
    insertion_in_tree(20);
    insertion_in_tree(8);
    insertion_in_tree(7);
    insertion_in_tree(15);
    insertion_in_tree(13);
    for(int i=0;i<30;i++){
        if(tree[i]=='\0'){
            cout<<"- ";
            continue;
        }
        cout<<tree[i]<<" ";
    }
    return 0;
}

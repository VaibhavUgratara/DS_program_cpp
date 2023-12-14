#include<iostream>
using namespace std;
int tree[30];

void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
int find(int val){
    for(int i=0;i<30;i++){
        if(tree[i]==val){
            return i;
        }
    }
    return -1;
}
bool isLeft(int val){
    int i=find(val);
    if((tree[2*i+1]=='\0')&&(i<30)){
        return 0;
    }
    return 1;
}
bool isRight(int val){
    int i=find(val);
    if((tree[2*i+2]=='\0')&&(i<30)){
        return 0;
    }
    return 1;
}


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

int l_large(int i){
    int x=2*i+1;
    while(tree[2*x+2]!='\0'){
        x=2*x+2;
    }
    return x;
}

int r_small(int i){
    int x=2*i+2;
    while(tree[2*x+1]!='\0'){
        x=2*x+1;
    }
    return x;
}

void deletion(int val){
    int index=find(val);
    int f=index;
    if(index==-1){
        cout<<"No such element present."<<endl;
        return;
    }
    if(isLeft(val)){
        f=l_large(index);
        swap(tree[index],tree[f]);
        deletion(val);
        return;
    }
    else if(isRight(val)){
        f=r_small(index);
        swap(tree[index],tree[f]);
        deletion(val);
        return;
    }
    if((!isLeft(tree[index]))&&(!isRight(tree[index]))){
        tree[index]='\0';
    }
}

int main(){
    for(int i=0;i<30;i++){
        tree[i]='\0';
    }
    insertion_in_tree(10);
    insertion_in_tree(12);
    insertion_in_tree(5);
    insertion_in_tree(4);
    insertion_in_tree(20);
    insertion_in_tree(8);
    insertion_in_tree(7);
    insertion_in_tree(13);
    for(int i=0;i<30;i++){
        if(tree[i]=='\0'){
            continue;
        }
        cout<<i<<"->"<<tree[i]<<". ";
    }
    cout<<endl;
    deletion(10);
    for(int i=0;i<30;i++){
        if(tree[i]=='\0'){
            continue;
        }
        cout<<i<<"->"<<tree[i]<<". ";
    }




    return 0;
}

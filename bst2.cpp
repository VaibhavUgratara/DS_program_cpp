#include<iostream>
using namespace std;
const int max_len=30;
int len;

int* create_tree(int n){
    int *tree=new int(n);
    for(int i=0;i<n;i++){
        tree[i]='\0';
    }
    len=n;
    return tree;
}

void insertion(int *tree,int val,int i=0){
    if(i>=len){
        cout<<"Full"<<endl;
        return;
    }
    if(tree[i]=='\0'){
        tree[i]=val;
        return;
    }
    if(tree[i]>=val){
        insertion(tree,val,2*i+1);
    }
    else{
        insertion(tree,val,2*i+2);
    }
}
void pre_order(int *tree,int i=0){
    cout<<"Index: "<<i<<" || Element: "<<tree[i]<<endl;
    if(tree[2*i+1]!='\0'){
        pre_order(tree,2*i+1);
    }
    if(tree[2*i+2]!='\0'){
        pre_order(tree,2*i+2);
    }
}

int find(int *tree,int val,int i=0){
    int res=-1;
    if(i >= len){
        return -1;
    }
    if(tree[i]==val){
        return i;
    }
    if((tree[2*i+1]!='\0')&& (res==-1)){
        res=find(tree,val,2*i+1);
    }
    if((tree[2*i+2]!='\0')&& (res==-1)){
        res=find(tree,val,2*i+2);
    }
    return res;
}


int l_large(int *tree,int i){
    int x=2*i+1;
    while(tree[2*x+2]!='\0'){
        x=2*x+2;
    }
    return x;
}

int r_small(int *tree,int i){
    int x=2*i+2;
    while(tree[2*x+1]!='\0'){
        x=2*x+1;
    }
    return x;
}

void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

void deletion(int *tree,int val){
    int x=find(tree,val);
    if((tree[2*x+1]=='\0')&&(tree[2*x+2]=='\0')){
        tree[x]='\0';
        return;
    }
    if(x==-1){
        cout<<"Element not present"<<endl;
        return;
    }
    if((tree[2*x+1]!='\0')){
        swap(tree[x],tree[l_large(tree,x)]);
        deletion(tree,val);
    }
    else if((tree[2*x+2]!='\0')){
        swap(tree[x],tree[r_small(tree,x)]);
        deletion(tree,val);
    }
}

int height(int *tree,int i=0){
    int l_res=1,r_res=1;
    if((tree[i]=='\0')||(i >= len)){
        return 0;
    }
    if(tree[2*i+1]!='\0'){
        l_res=1+height(tree,2*i+1);
    }
    if(tree[2*i+2]!='\0'){
        r_res=1+height(tree,2*i+2);
    }
    if(l_res>r_res){
        return l_res;
    }
    return r_res;

}

int main(){
    int n=30;
    int *tree=create_tree(n);
    insertion(tree,10);
    insertion(tree,5);
    insertion(tree,4);
    insertion(tree,12);
    insertion(tree,20);
    insertion(tree,8);
    deletion(tree,5);
    deletion(tree,8);
    deletion(tree,20);
    // pre_order(tree);
    cout<<height(tree);
    delete[] tree;
    return 0;
}

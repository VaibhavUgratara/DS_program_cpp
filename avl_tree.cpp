#include<iostream>
#include<cmath>
using namespace std;

void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

int* create_tree(int n){
    int *tree=new int(n);
    for(int i=0;i<n;i++){
        tree[i]='\0';
    }
    return tree;
}

bool isLeft(int *tree,int i){
    if(*(tree+(2*i+1))!='\0'){
        return 1;
    }
    return 0;
}

bool isRight(int *tree,int i){
    if(*(tree+(2*i+2))!='\0'){
        return 1;
    }
    return 0;
}

int get_height(int *tree,int i=0){
    int l_res=1,r_res=1;
    if((*(tree+i)=='\0')||(i>29)){
        return 0;
    }
    if(isLeft(tree,i)){
        l_res=l_res+get_height(tree,2*i+1);
    }
    if(isRight(tree,i)){
        r_res=r_res+get_height(tree,2*i+2);
    }
    if(l_res>r_res){
        return l_res;
    }
    return r_res;
}



int balance_factor(int *tree,int i){
    return get_height(tree,2*i+1)-get_height(tree,2*i+2);
}

void right_rotate(int *tree,int i){
    int x=2*i+2;
    swap(tree+i,tree+x);
    swap(tree+x,tree+2*x+2);
    *(tree+2*i+1)=*(tree+2*x+2);
    *(tree+2*x+2)='\0';
}

void left_rotate(int *tree,int i){
    int x=2*i+1;
    swap(tree+i,tree+x);
    swap(tree+x,tree+2*x+1);
    *(tree+2*i+2)=*(tree+2*x+1);
    *(tree+2*x+1)='\0';
}

void insert_in_tree(int *tree,int val,int index=0){
    if(*(tree+index)=='\0'){
        *(tree+index)=val;
        return;
    }
    if(index>29){
        cout<<"Out of bound"<<endl;
        return;
    }
    if(*(tree+index)<val){
        insert_in_tree(tree,val,2*index+2);
    }
    else{
        insert_in_tree(tree,val,2*index+1);
    }
    int bf=balance_factor(tree,index);
    if((bf<-1)||(bf>1)){
        if((isLeft(tree,index)) && (isLeft(tree,2*index+1))){
            left_rotate(tree,index);
        }
        else if((isLeft(tree,index)) && (isRight(tree,2*index+1))){
            int x=2*index+1;
            swap((tree+x),(tree+2*x+2));
            *(tree+2*x+1)=*(tree+2*x+2);
            *(tree+2*x+2)='\0';
            left_rotate(tree,index);
            }
        else if((isRight(tree,index)) && (isRight(tree,2*index+2))){
            right_rotate(tree,index);
        }
        else if((isRight(tree,index)) && (isLeft(tree,2*index+2))){
                int x=2*index+2;
                swap((tree+x),(tree+2*x+1));
                *(tree+2*x+2)=*(tree+2*x+1);
                *(tree+2*x+1)='\0';
                right_rotate(tree,index);
            }
        
        }

}


int main(){
    int *tree=create_tree(30);
    insert_in_tree(tree,1);
    insert_in_tree(tree,2);
    insert_in_tree(tree,3);
    insert_in_tree(tree,4);
    insert_in_tree(tree,5);
    for(int i=0;i<30;i++){
        if(tree[i]=='\0'){
            continue;
        }
        cout<<i<<"->"<<tree[i]<<" ";
    }
    cout<<endl;

    return 0;
}
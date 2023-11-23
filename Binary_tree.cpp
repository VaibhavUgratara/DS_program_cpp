#include <iostream>
using namespace std;
char tree[30];
void set_Root(char data){
    if (tree[0]!='\0'){
        cout<<"Data already present"<<endl;
    }
    else{
        tree[0]=data;
    }
}

void set_left(int root,char data){
    if(tree [root]=='\0'){
        cout<<"Enter parent data first"<<endl;
    }
    else{
        tree[root*2+1]=data;
    }
}
void set_right(int root,char data){
    if(tree [root]=='\0'){
        cout<<"Enter parent data first"<<endl;
    }
    else{
        tree[root*2+2]=data;
    }
}


//pre-order
void pre_order(int i=0){
    cout<<tree[i];
    if(tree[2*i+1]!='\0'){
        pre_order(2*i+1);}
    if(tree[2*i+2]!='\0'){
        pre_order(2*i+2);
    }
}


//in-order
void in_order(int i=0){
    if(tree[2*i+1]!='\0'){
        in_order(2*i+1);
    }
    cout<<tree[i];
    if(tree[2*i+2]!='\0'){
        in_order(2*i+2);
    }
}


//post-order
void post_order(int i=0){
    if(tree[2*i+1]!='\0'){
        post_order(2*i+1);
    }
    if(tree[2*i+2]!='\0'){
        post_order(2*i+2);
    }
    cout<<tree[i];
}


int main() {
    set_Root('a');
    set_left(0,'b');
    set_right(0,'c');
    set_left(1,'d');
    set_right(1,'e');
    set_right(2,'f');
    set_left(4,'g');
    
    
    
    pre_order();
    cout<<endl;
    
    
    in_order();
    cout<<endl;
    
    
    post_order();
    
    
    return 0;
}

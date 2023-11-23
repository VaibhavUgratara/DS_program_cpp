#include <iostream>
using namespace std;
char tree[10];
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
void run(int i){
    cout<<tree[i]<<endl;
    if(tree[2*i+1]!='\0'){
        run(2*i+1);
    if(tree[2*i+2]!='\0'){
        run(2*i+2);
    }
}
}
int main() {
    set_Root('a');
    set_left(0,'b');
    set_right(0,'c');
    set_left(1,'d');
    run(0);
    return 0;
}

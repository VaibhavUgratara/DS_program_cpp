// Stack using linked list
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack{
    private:
    Node *top=NULL;
    public:
    void push(int val){
        Node *ptr=new Node;
        if(!ptr){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        ptr->data=val;
        ptr->next=top;
        top=ptr;
    }
    void pop(){
        if(top==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<top->data<<endl;
        Node *temp=top;
        top=top->next;
        free (temp);
    }
};

int main() {
    Stack s;
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}

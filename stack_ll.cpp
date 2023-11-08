#include<iostream>
using namespace std;
const int MAX_SIZE=10;

class Node{
    public:
        int data;
        Node *n;
        Node(int d){
            this->data=d;
            this->n=NULL;
        }
};

class Stack{
    public:
        Node *top_node;
        int top;
        Stack(){
            top=-1;
            top_node=NULL;
        }
        void PUSH(int d){
            if(this->top==MAX_SIZE-1){
                cout<<"Overflow"<<endl;
            }
            else{
                Node *temp= new Node(d);
                temp->n=top_node;
                top_node=temp;
                top+=1;
            }
        }
        void POP(){
            if(top_node==NULL){
                cout<<"Underflow"<<endl;
            }
            else{
                Node *temp;
                temp=top_node;
                top_node=top_node->n;
                free(temp);
                top--;
            }
        }
};

int main(){
    Stack s1;
    s1.PUSH(10);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(4);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.PUSH(4);
    s1.PUSH(20);
    s1.PUSH(20);
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    s1.POP();
    return 0;
}
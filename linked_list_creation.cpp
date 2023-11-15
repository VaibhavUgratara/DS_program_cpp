#include<iostream>
using namespace std;
//defining a structure
struct Node{
    int data;
    struct Node *next;
};

//inserting data in linked list
Node* CreateList(int numberOfnodes){
    Node *s=new Node;
    Node *first=s;
    for(int i=1;i<=numberOfnodes;i++){
        cout<<"Enter Data of "<<i<<"th element: ";
        cin>>s->data;
        if(i!=numberOfnodes){
            s->next=new Node;
            s=s->next;
        }
        else{
            s->next=NULL;
        }
    }
    return first;
}

//printing whole list
void PrintList(Node *first){
    while(first!=NULL){
        cout<<first->data<<endl;
        first=first->next;
    }
}


int main(){
    Node *head;
    int ListLength=5;
    head=CreateList(ListLength);
    PrintList(head);
    return 0;
}

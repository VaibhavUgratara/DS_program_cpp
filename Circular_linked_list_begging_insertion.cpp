#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

void insert(Node *&head, Node *ptr){
    Node *temp;
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=head;
    head=ptr;
}
int main() {
    Node n[3],*temp,*head;
    n[0].data=1;
    n[1].data=2;
    n[2].data=3;
    
    n[0].next=&n[1];
    n[1].next=&n[2];
    n[2].next=&n[0];
    head=&n[0];
    
    
    temp=head;
    cout<<"Before:"<<endl;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
    
    
    Node n1;
    n1.data=4;
    
    
    insert (head,&n1);
    
    
    temp=head;
    
    
    cout<<"After:"<<endl;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    return 0;
}

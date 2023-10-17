#include<iostream>
using namespace std;
struct l_list{
    int info;
    l_list *nxt;
};

//deleting from head
void head_delete(l_list **head){
    if(*head==NULL){
        cout<<"Underflow"<<endl;
    }
    else{
        l_list *temp=*head;
        *head=temp->nxt;
        free(temp);
    }
}

//deleting from last
void end_deletion(l_list *head){
    l_list *temp=head,*temp2;
    if(head==NULL){
        cout<<"Underflow"<<endl;
    }
    else{
        while(temp->nxt!=NULL){
            temp2=temp;
            temp=temp->nxt;
        }
        temp2->nxt=NULL;
        free(temp);
    }
}

//deletion from middle
void mid_del(l_list **head,int node){
    if(head==NULL){
        cout<<"Underflow"<<endl;
    }
    else if(node==1){
        head_delete(head);
    }
    else{
        int c=1;
        l_list *temp=*head,*temp2=temp;
        while(c<node){
            temp2=temp;
            temp=temp->nxt;
            c++;
        }
        temp2->nxt=temp->nxt;
        free(temp);
    }
}

int main(){
    l_list a,b,c,d,*first=&a;
    a.info=2;
    b.info=3;
    c.info=4;
    d.info=5;
    a.nxt=&b;
    b.nxt=&c;
    c.nxt=&d;
    d.nxt=NULL;
    cout<<"Before deletion:"<<endl;
    for(l_list *temp=first;temp!=NULL;temp=temp->nxt){
        cout<<temp->info<<" ";
    }
    cout<<endl<<"Deleting node 3"<<endl;
    mid_del(&first,3);
    for(l_list *temp=first;temp!=NULL;temp=temp->nxt){
        cout<<temp->info<<" ";
    }
    return 0;
}
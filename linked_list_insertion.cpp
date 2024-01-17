#include<iostream>
using namespace std;
struct l_list{
    int data;
    l_list *nxt;
};

//insertion at end
void end_insertion(l_list **head,l_list *ptr){
    if(ptr==NULL){
        cout<<"Overflow"<<endl;
    }
    else{
        l_list *temp;
        temp=*head;
        while(temp->nxt!=NULL){
            temp=temp->nxt;
        }
        temp->nxt=ptr;
    }
    ptr->nxt=NULL;
}

//insertion at start
void begin_insertion(l_list **head,l_list *ptr){
    if(*head==NULL){
        cout<<"Overflow"<<endl;
    }
    else{
        l_list *temp=*head;
        *head=ptr;
        ptr->nxt=temp;
    }
}

//insertion in middle (node starts from 1 and goes to n i.e. size of linked list)
void insert(l_list **head,l_list *ptr,int node){
    if(*head==NULL){
        cout<<"Overflow"<<endl;
    }
    else if(node==1){
        ptr->nxt=*head;
        *head=ptr;
    }
    else{
        int i=1;
        l_list *t1,*t2;
        t1=*head;
        while(i<node){
            t2=t1;
            t1=t1->nxt;
            i++;
        }
        t2->nxt=ptr;
        ptr->nxt=t1;
    }
    
}
int main(){
    l_list a,b,c,*first=&a, *c_ptr=&c;
    a.data=1;
    b.data=2;
    a.nxt=&b;
    b.nxt=NULL;
    cout<<"Original List"<<endl;
    for(l_list *temp=first;temp!=NULL;temp=temp->nxt){
        cout<<temp->data<<" ";
    }
    cout<<endl;
    c.data=3;
    begin_insertion(&first,c_ptr);
    cout<<"Inserted at beggining"<<endl;
    for(l_list *temp=first;temp!=NULL;temp=temp->nxt){
        cout<<temp->data<<" ";
    }
    cout<<endl;
    l_list d,*d_ptr=&d;
    d.data=4;
    end_insertion(&first,d_ptr);
    cout<<"Inserted at end"<<endl;
    for(l_list *temp=first;temp!=NULL;temp=temp->nxt){
        cout<<temp->data<<" ";
    }
    cout<<endl;
    l_list e,*e_ptr=&e;
    int n;
    cout<<"Enter Position: ";
    cin>>n;
    cout<<"Enter Data: ";
    cin>>e.data;
    insert(&first,e_ptr,n);
    cout<<"Inserted at "<<n<<endl;
    for(l_list *temp=first;temp!=NULL;temp=temp->nxt){
        cout<<temp->data<<" ";
    }
    return 0;
}

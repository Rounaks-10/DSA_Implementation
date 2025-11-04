#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;
    // constructor
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insert_at_head(node*&head ,int data){
    node*temp=new node(data);
    temp->next=head;
    head->prev = temp; 
    head=temp;
}
void insert_at_tail(node*&tail ,int data){
    node*temp=new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insert_at_position(node*&head, node*&tail,int data,int position){
    if(position==1){
        insert_at_head(head, data);
        return;
    }
    node*temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insert_at_tail(tail, data);
        return;
    }
    node*newNode=new node(data);
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}
void delete_node(node*&head, node*&tail, int position){
    if(position==1){
        node*temp=head;
        head=head->next;
        if(head!=NULL) head->prev=NULL; // Update head's prev if it exists
        delete temp;
        return;
    }
    node*current=head;
    int count=1;
    while(count<position && current!=NULL){
        current=current->next;
        count++;
    }
    if(current==NULL) return; // Position is out of bounds
    if(current->next==NULL){ // If it's the tail
        tail=current->prev;
        tail->next=NULL;
    } else {
        current->next->prev=current->prev;
    }
    current->prev->next=current->next;
    delete current;
}
int main() {
    node* node1=new node(10);
    node*head=node1;
    node*tail=node1;
    insert_at_head(head,20);
    insert_at_tail(tail,30);
    insert_at_head(head,15);
    insert_at_position(head,tail, 25, 5);
    delete_node(head, tail, 2);
    print(head);
return 0;
}
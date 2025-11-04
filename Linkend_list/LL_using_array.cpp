#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    // constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insert_at_tail(node*&tail ,int data){
    node*temp=new node(data);
    tail->next=temp;
    tail=temp;
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    int arr[5]={1,2,3,4,5};
    node* node1=new node(arr[0]);
    node*head=node1;
    node*tail=node1;
    for(int i=1;i<5;i++){
        insert_at_tail(tail, arr[i]);
    }
    print(head);
    
return 0;
}
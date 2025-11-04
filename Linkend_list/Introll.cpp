#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    // constructor
    node(int data,node* next){
        this->data=data;
        this->next=next;
    }
};
void Insert_at_head(node*&head,int d){
    // new node
    node* temp =new node(d,NULL);
    temp->next=head;
    head=temp;
   
}
void Insert_at_tail(node*&tail,int d){
    // new node
    node* temp=new node(d,NULL);
    tail->next=temp;
    tail=temp;
}
void insert_at_any_position(node*&head ,int d ,int position){
    node *temp=new node(d,NULL);
    node *temp1=head;
    int count=1;
    if(position==1){
        Insert_at_head(head,d);
        return;
    }
    while(count< position-1){
        temp1=temp1->next;
        count++;
    }
    temp->next=temp1->next;
    temp1->next=temp;
    
}
void print(node*head){
    node * temp =head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void delete_node(node*&head,int position){
    if(position==1){
        node* temp=head;
        head=temp->next;
        delete temp;
    }
    else{
        node* current=head;
        node* previous=NULL;
        int count=1;
        while(count<position && current!=NULL){
            previous=current;
            current=current->next;
            count++;
        }
        if(current!=NULL){
            previous->next=current->next;
            delete current;
        }
        else{
            cout<<"Position out of bounds"<<endl;
        }
    }
}
int main() {
    node* n1=new node(10,NULL);
    node* n2=new node(20,n1);
    node* n3=new node(30,n2);
    // cout<<n3->next->data<<endl;
    // cout<<n3->next->next->data<<endl;
    // cout<<n2<<endl;
    cout<<n3->next<<endl;
    cout<<n2<<endl;
    cout<<n3<<endl;
    node * head=n3;
    node *tail=n1;
    Insert_at_head(head,100);
    cout<<"after inserting at head ";
    print(head);
    cout<<endl;
    Insert_at_tail(tail,5);
    cout<<"after inserting at tail ";
    print(head);
    cout<<endl;
    insert_at_any_position(head,10,6);
    print(head);
    cout<<endl;
    delete_node(head,1);
    print(head);
    cout<<endl;
    delete_node(head,5);
    print(head);
    cout<<endl;
    
    
    
return 0;
}
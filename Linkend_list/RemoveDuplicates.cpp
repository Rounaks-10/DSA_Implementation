#include<iostream>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insert_at_head(node*&head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node*temp=new node(data);
    temp->next=head;
    head=temp;
}
void insert_at_tail(node* &tail, int data) {
     // new node create
    node* temp = new node(data);
    tail -> next = temp;
    tail  = temp;
}
void insert_at_position(node*&head,node*&tail,int data,int position){
    if(position==1){
        insert_at_head(head, data);
        return;
    }
        int count=1;
        node*temp=head;
        while(count<position-1){
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
            insert_at_tail(temp, data);
            return; 
        }
        node*newnode=new node(data);
        newnode->next=temp->next;
        temp->next=newnode;
    

}

void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void removeduplicates(node*head){
    node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data == curr->next->data){
            node*temp=curr->next;
            curr->next=temp->next;
            temp->next=NULL; 
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
}
void removeunsorted(node*head){
    node*curr=head;
    while(curr!=NULL){
        node*temp=curr;
        while(temp!=NULL && temp->next!=NULL){
            if(curr->data == temp->next->data){
              node* todelete=temp->next;
              temp->next=todelete->next;
              todelete->next=NULL;
              delete(todelete);  
            }
            else{
            temp=temp->next;
            }
        }
        curr=curr->next;
    }
}
void usingmap(node*head){
    map<int,bool> visited;
    node* curr=head;
    node* prev=NULL;
    while(curr!=NULL&& curr->next!=NULL){
        if(visited[curr->data]==true){
            // node* temp = curr;
            prev->next = curr->next;
            curr->next = NULL;
            delete(curr);
        }
            visited[curr->data] = true;
            curr=curr->next;
            prev = curr;
    }

}
int main() {
    node* n1=new node(4);
    node*head=n1;
    node*tail=n1;
    insert_at_tail(tail,2);
    insert_at_tail(tail,5);
    insert_at_tail(tail,4); 
    insert_at_tail(tail,2);
    insert_at_tail(tail,2);
    insert_at_tail(tail,5);
    insert_at_tail(tail,4);
    print(head);
    cout << endl; 
    // removeduplicates(head);
    usingmap(head);
    print(head);

return 0;
}
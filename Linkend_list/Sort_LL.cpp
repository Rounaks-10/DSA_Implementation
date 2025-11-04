#include<iostream>
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

node* solve(node*head1,node*head2){
   
    node*curr1=head1;
    node*next1=curr1->next;
    node*curr2=head2;
    node*next2=curr2->next;
    if(head1->next==NULL){
        curr1->next=curr2;
        return head1;
    }
    while(next1!=NULL && curr2!=NULL){
        if(curr1->data <=curr2->data && next1->data>=curr2->data){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return head1;
            }
        }
    }
    return head1;
}
node * merge(node*head1,node*head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    if(head1->data<=head2->data){
        return solve(head1,head2);
    }else{
        return solve(head2,head1);
    }
}

node* sort(node*head){
    node*zeroHead=new node(-1);
    node*zeroTail=zeroHead;
    node*oneHead=new node(-1);
    node*oneTail=oneHead;
    node*twoHead=new node(-1);
    node*twoTail=twoHead;

    node* curr=head;
    while(curr!=NULL){
        if(curr->data ==0){
            insert_at_tail(zeroTail,curr->data);
        }else if(curr->data==1){
            insert_at_tail(oneTail,curr->data);
        }else{
            insert_at_tail(twoTail,curr->data);
        }
        curr=curr->next;
    }
    if(oneHead->next!=NULL){
    zeroTail->next=oneHead->next;
} else{
    zeroTail->next=twoHead->next;
}
oneTail->next=twoHead->next;

    return zeroHead->next;
}
int main() {
      node* n1=new node(1);
    node*head1=n1;
    node*tail1=n1;
    insert_at_tail(tail1,3);
    insert_at_tail(tail1,5);
    insert_at_tail(tail1,7); 
    insert_at_tail(tail1,9);
    print(head1);
    cout << endl;
    node* n2=new node(2);
    node*head2=n2;
    node*tail2=n2;
    insert_at_tail(tail2,4);
    insert_at_tail(tail2,6);
    insert_at_tail(tail2,8); 
    insert_at_tail(tail2,10);
    print(head2);
    cout << endl;
    // print(sort(head));
    cout<<"After merging the two linked lists: ";
    print(merge(head1,head2));
    
return 0;
}
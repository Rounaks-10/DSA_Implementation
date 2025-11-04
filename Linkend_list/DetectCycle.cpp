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
 // Cycle Detection using Floyd's Cycle-Finding Algorithm
node* Detect_Cycle(node*&head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next; // Move slow pointer by 1 step
        fast=fast->next->next; // Move fast pointer by 2 steps
        if(slow==fast){ // If they meet, there is a cycle
            return slow;
        }
    }
    return NULL;
 }

bool detectcycle(node*&head){
    map<node*,bool> visited;
    node*temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

node* Starting_Node(node*&head){
    node* intermidate=Detect_Cycle(head);
    node*slow=head;
    while(slow!=intermidate){
        slow=slow->next;
        intermidate=intermidate->next;
    }
    return slow;
}

node* Remove_Cycle(node*&head){
    node*start=Starting_Node(head);
    node*temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=NULL;
}



int main() {
    node* n1=new node(10);
    node*head=n1;
    node*tail=n1;
    insert_at_position(head,tail,50,1);
    insert_at_tail(tail,30);
    insert_at_position(head,tail,20,2);
    insert_at_position(head,tail,40,3);
    print(head);
    cout << endl;
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    tail->next=head->next; // Creating a cycle for testing
    cout<<Detect_Cycle(head)->data<<endl;
    cout<<Starting_Node(head)->data<<endl;
    // Remove_Cycle(head);
    cout<<Detect_Cycle(head)<<endl;
    if(detectcycle(head)){
        cout<<"cycle present"<<endl;
    }else{
        cout<<"cycle is not present"<<endl;
    }
     
    
return 0;
}
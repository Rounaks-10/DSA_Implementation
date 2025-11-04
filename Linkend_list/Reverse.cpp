#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_position(node*&head, int data,int position){
    if(position==1){
        node* newnode= new node(data);
        newnode->next = head;
        head->prev = newnode;
        head=newnode;
        return;
    }
    else{
        int count=1;
        node* temp = head;
        while(count<position-1){
            temp = temp->next;
            count++;
        }
        if(temp->next == NULL) {
            node* newnode = new node(data);
            temp->next = newnode;
            newnode->prev = temp;
        } else {
            node* newnode = new node(data);
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

}
node* reverse(node*&head){
    node*current = head;
    node*prev=NULL;
    while(current!=NULL){
        prev = current->prev; 
        current->prev=current->next;
        current->next=prev;
        current=current->prev;
    }
    return prev->prev;
    
}
void print(node*head) {
    node*temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    node*node1 = new node(10);
    node*head=node1;
    node*tail=node1;
    insert_at_position(head, 20, 1);
    insert_at_position(head, 30, 2);
    insert_at_position(head, 40, 3);

    print(head);
    print(reverse(head));

return 0;
}
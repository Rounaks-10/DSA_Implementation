#include<iostream>
using namespace std;
class StackNode{
    public: 
    int data;
    StackNode*next;

    StackNode(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Stack{
    public:
    StackNode*top; 
    int size;

    Stack(){
        top=NULL;
        size=0;
    }


void push(int data){
    StackNode*temp=new StackNode(data);
    temp->next=top;
    top=temp;
    size++;
}
void pop(){
    if(top==NULL){
        cout<<"Stack underflow"<<endl;
        return;
    }
    StackNode*temp=top;
    top=top->next;
    delete temp;
    size--;
}
void peek(){
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Top element is: "<<top->data<<endl;
}
int stacksize(){
    return size;
}

};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.peek();
    cout<<s.stacksize()<<endl; 

    return 0;
}
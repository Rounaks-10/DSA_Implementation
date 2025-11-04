#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int top;
    int size;

    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
void push(int data){
    if(size - top >1){
        top++;
        arr[top]=data;
    }else{
        cout<<"Stack overflow"<<endl;
        return;
    }
}
void pop(){
    if(top==-1){
        cout<<"Stack underflow"<<endl;
        return;
    }
    else{
        top--;
    }
}
int peek(){
    if(top>=0){
    return arr[top];
    }
    else{
        cout<<"Stack is empty"<<endl;
        return -1;
    }
}
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

}
};
int main() {
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout<<s.peek();
     
return 0;
}
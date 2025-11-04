#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;
class node{
    public:
 int data;
 node*left;
 node*right;

 node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
 }

};
node* buildtree(node*root){
    int data;
    cout<<"Enter the data:";
    cin>>data;

    if(data==-1){
        return NULL;
    }
    root=new node(data);
    cout<<"Enter data for left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
node *levelordertraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL); // to mark the end of the current level

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); // push NULL to mark the end of the next level
            }
        }
        else{
             cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    }
}
int countleaf(node*root){
    queue<node*>q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp->left==NULL && temp->right==NULL){
            count++;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return count;
}
node* reverselevelordertraversal(node*root){
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    q.push(NULL); // to mark the end of the current level

    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        s.push(temp);
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); // push NULL to mark the end of the next level
            }
        }
        else{
        if(temp->right){
            q.push(temp->right);
        }     
        if(temp->left){
            q.push(temp->left);
        }
    }
    }
    while(!s.empty()){
        if(s.top() == NULL) {
            cout <<endl;
        }
        else{
            cout << s.top()->data << " ";
        }
        s.pop();
    }
}
void buildfromlevelorder(node*&root){
    queue<node*> q;
    cout<<"Enter data:";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<"Enter for left child"<<temp->data;
        int leftdata;
        cin>>leftdata;
        if(leftdata==-1){
            temp->left=NULL;
        }
        else{
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter for right child"<<temp->data;
        int rightdata;
        cin>>rightdata;
        if(rightdata==-1){
            temp->right=NULL;
        }
        else{
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 6 -1 -1

int main() {
    node*root=NULL;
    root=buildtree(root);
    // cout<<"Level order traversal of the binary tree is:"<<endl;
    // levelordertraversal(root);
    // cout<<"Reverse level order traversal of the binary tree is:"<<endl;
    // reverselevelordertraversal(root);

    // buildfromlevelorder(root);
    // cout<<"Level order traversal of the binary tree is:"<<endl;
    // levelordertraversal(root);
    // cout<<"Count of leaf nodes in the binary tree is:"<<countleaf(root)<<endl;
    
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* minE(Node*root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* buildbsTree(Node*root,int data){

    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        root->right=buildbsTree(root->right,data);
    }
    else{
        root->left=buildbsTree(root->left,data);
    }
    return root;
}
Node*deletenode(Node* root,int data){
    if(root==NULL){
        return root;
    }
    if(root->data==data){
        //0 node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 node
        if(root->left==NULL && root->right!=NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }
        //2 node
        if(root->left!=NULL && root->right!=NULL){
            int minElement=minE(root->right)->data;
            root->data=minElement;
            root->right=deletenode(root->right,minElement);
            return root;
        }
    }
    if(root->data>data){
       root->left=deletenode(root->left,data);
        return root;
    }
    else{
        root->right=deletenode(root->right,data);
        return root;
    }
    return root;
}
Node *levelordertraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL); // to mark the end of the current level

    while(!q.empty()){
        Node*temp=q.front();
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
int main() {
    Node* root = NULL;
    int data;
    cin>>data;
    while(data!=-1){
        root=buildbsTree(root,data);
        cin>>data;
    }
    cout<<"Level order traversal before deletion:"<<endl;
    levelordertraversal(root);
    cout<<"Level order traversal after deletion:"<<endl;
    levelordertraversal(deletenode(root,8));
    return 0;
}
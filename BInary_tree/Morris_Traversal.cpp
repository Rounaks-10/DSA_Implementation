#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node*buildTree(Node*root){
    int val;
    cout<<"Enter the value for node";
    cin>>val;
    if(val == -1) {
        return NULL;
    }
    root=new Node(val);
    cout<<"Enter left child of "<<val<<": ";
    root->left=buildTree(root->left);
    cout<<"Enter right child of "<<val<<": ";
    root->right=buildTree(root->right);
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
void Morris_Traversal(Node*root){
    Node*current=root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current=current->right;
        }
        else{
            Node*predessor=current->left;
            while(predessor->right!=NULL && predessor->right!=current){
                predessor=predessor->right;
            }
            if(predessor->right==NULL){
                predessor->right=current;
                current=current->left;
            }
            else{
                predessor->right=NULL;
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
}
int main() {
    Node* root = NULL;
    root = buildTree(root);
    levelordertraversal(root);
    cout<<endl;
    Morris_Traversal(root);
    return 0;
}
//1 2 4 -1 -1 5 -1 -1 3 -1 -1
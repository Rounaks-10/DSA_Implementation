#include<iostream>
#include<queue>
#include<vector>
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
Node* buildtree(Node*root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data>data){
        root->left=buildtree(root->left,data);  
    }
    else{
        root->right=buildtree(root->right,data);
    }
    return root;
}
void levelorder(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
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
void inorder(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

int main() {
    Node*root=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        root=buildtree(root,data);
        cin>>data;
    }
    levelorder(root);
    vector<int> ans;
    inorder(root, ans);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
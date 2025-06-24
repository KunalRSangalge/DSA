#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void preorder(Node*node){ //TC:O(n), SC:O(n)
    if(node==NULL)return ;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
void preorder_iterative(Node*root){
    if(root==NULL)return;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        cout<<node->data<<" ";
        if(node->right!=NULL)st.push(node->right);
        if(node->left!=NULL)st.push(node->left);
    }
}
void inorder(Node*node){ //TC:O(n), SC:O(n)
    if(node==NULL)return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
void inorder_iterative(Node*root){
    if(root==NULL)return;
    stack<Node*>st;
    Node*curr = root;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr = st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}
void postorder(Node*node){ //TC:O(n), SC:O(n)
    if(node==NULL)return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}
void postorder_iterative(Node*root){
    if(root==NULL)return;
    stack<Node*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        Node* node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left!=NULL)st1.push(node->left);
        if(node->right!=NULL)st1.push(node->right);
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}
void level_order_traversal(Node*root){
    vector<int>ans;
    if(root==NULL)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        ans.push_back(node->data);
        if(node->left!=NULL)q.push(node->left);
        if(node->right!=NULL)q.push(node->right);
    }
    for(auto it : ans)cout<<it<<" ";
    cout<<endl;
}
int main(){
    Node*root = new Node(1);
}
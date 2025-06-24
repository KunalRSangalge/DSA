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
bool path(Node* root, int target,vector<int>&v){
    if(root==NULL)return false;
    v.push_back(root->data);
    if(root->data==target)return true;
    bool flag = path(root->left,target,v) || path(root->right,target,v);
    if(flag)return true;
    v.pop_back();
    return false; 
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    vector<int>ans;
    path(root,6,ans);
    for(auto it : ans)cout<<it<<" ";cout<<endl;
}
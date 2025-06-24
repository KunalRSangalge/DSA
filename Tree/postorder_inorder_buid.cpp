//given postorder and inorder, build a BT
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->val=data;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode* build(int postStart,int postEnd,int inStart,int inEnd,
                vector<int>&postorder,vector<int>&inorder,map<int,int>&mpp){
    if(postStart > postEnd || inStart > inEnd)return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);
    int root_idx = mpp[postorder[postEnd]];
    int left = root_idx-inStart;
    root->left = build(postStart,postStart+left-1,root_idx-left,root_idx-1,postorder,inorder,mpp);
    root->right = build(postStart+left,postEnd-1,root_idx+1,inEnd,postorder,inorder,mpp);
    return root;
}
TreeNode* buildTree(vector<int>&inorder,vector<int>&postorder){
    int n = postorder.size();
    map<int,int>mpp;
    for(int i=0;i<n;i++)mpp[inorder[i]]=i;
    TreeNode* root = build(0,n-1,0,n-1,postorder,inorder,mpp);
    return root;
}
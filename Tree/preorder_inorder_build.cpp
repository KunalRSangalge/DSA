//given preorder and inorder, build a BT
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* build(int preStart,int preEnd,int inStart,int inEnd,
                vector<int>&preorder,vector<int>&inorder,map<int,int>&mpp){

    if(preStart > preEnd || inStart > inEnd)return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int root_idx = mpp[preorder[preStart]];
    int left = root_idx-inStart;

    root->left = build(preStart+1,preStart+left,root_idx-left,root_idx-1,preorder,inorder,mpp);
    root->right = build(preStart+left+1,preEnd,root_idx+1,inEnd,preorder,inorder,mpp);

    return root;
    
}
TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder){
    int n = preorder.size();
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[inorder[i]]=i;
    }
    TreeNode* root = build(0,n-1,0,n-1,preorder,inorder,mpp);
    return root;
}
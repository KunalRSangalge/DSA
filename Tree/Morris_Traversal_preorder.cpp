//morris traversal is traversal in O(n) time but O(1) space
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->left=NULL;
        this->right=NULL;
        this->val=data;
    }
};
vector<int> Morris(TreeNode* root){
    vector<int>preorder;
    TreeNode* cur = root;
    while(cur!=NULL){
        if(cur->left == NULL){
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;
            while(prev->right!=NULL && prev->right!=cur) prev = prev->right;

            if(prev->right==NULL){
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}
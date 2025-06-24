#include<bits/stdc++.h>
using namespace std;
//width is maximum number of nodes between two nodes in the same level
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        long long ans = 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            long long size = q.size();
            long long mini = q.front().second;
            long long first = q.front().second;
            long long last = q.back().second;
            for(long long i=0;i<size;i++){
                long long cur_idx = q.front().second - mini;
                TreeNode* cur_node = q.front().first;
                q.pop();
                if(cur_node->left!=NULL) q.push({cur_node->left,(long long)2*cur_idx+1});
                if(cur_node->right!=NULL) q.push({cur_node->right,(long long)2*cur_idx+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};
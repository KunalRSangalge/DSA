#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it])dfs(it,vis,adj,st);
        }
        st.push(node);
    }
    void dfs2(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it])dfs2(it,vis,adj);
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){ //storing in order  
            if(!vis[i])dfs(i,vis,adj,st);
        }
        vector<vector<int>>radj(n);
        for(int i=0;i<n;i++){
            for(auto it : adj[i])radj[it].push_back(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)vis[i]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node,vis,radj);
                ans++;
            }
        }
        return ans;
    }
};
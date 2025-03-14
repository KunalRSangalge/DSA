#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>adj,vector<int>&ans,int node,vector<int>&vis){
    vis[node]=1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(adj,ans,it,vis);
        }
    }
}
//TC - O(v+E)
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}
int main(){
    int V;
    vector<vector<int>>adj(V);
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int N;
vector<int>ans;
vector<int>NodeCount;
vector<vector<int>>adj;

void dfs(int node,int parent){
    for(auto it : adj[node]){ //it is child of node here
        if(it==parent)continue;
        dfs(it,node);
        NodeCount[node]+=NodeCount[it];
        ans[node]+=(ans[it]+NodeCount[it]);
    } 
}

void dfs2(int node,int parent){
    for(auto it : adj[node]){
        if(it==parent)continue;
        ans[it]=ans[node]-NodeCount[it]+(N-NodeCount[it]);
        dfs2(it,node);
    }
}

vector<int>sumofDistances(int n,vector<vector<int>>&edges){
    N=n;
    adj.resize(n);
    for(auto e : edges){
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans.resize(n,0);
    NodeCount.resize(n,1);
    dfs(0,-1);
    dfs2(0,-1);
    return ans;
}